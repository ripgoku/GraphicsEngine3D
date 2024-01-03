#include "IndexedCube.h"
#include <glm/vec3.hpp>
#include <glm/gtx/norm.hpp>

IndexedCube::IndexedCube(float size) : sideLength(size) {
    // Definiuj wierzcho³ki szeœcianu
    vertices = {
        -0.5f * size, -0.5f * size, -0.5f * size, // Vertex 0
         0.5f * size, -0.5f * size, -0.5f * size, // Vertex 1
         0.5f * size,  0.5f * size, -0.5f * size, // Vertex 2
        -0.5f * size,  0.5f * size, -0.5f * size, // Vertex 3
        -0.5f * size, -0.5f * size,  0.5f * size, // Vertex 4
         0.5f * size, -0.5f * size,  0.5f * size, // Vertex 5
         0.5f * size,  0.5f * size,  0.5f * size, // Vertex 6
        -0.5f * size,  0.5f * size,  0.5f * size  // Vertex 7
    };

    // Definiuj indeksy œcian szeœcianu
    indices = {
        0, 1, 2, 2, 3, 0, // Przód
        4, 5, 6, 6, 7, 4, // Ty³
        0, 4, 7, 7, 3, 0, // Lewa
        1, 5, 6, 6, 2, 1, // Prawa
        3, 2, 6, 6, 7, 3, // Góra
        0, 1, 5, 5, 4, 0  // Dó³
    };

    // Ustaw kolor dla ka¿dego wierzcho³ka
    colors.resize(vertices.size(), 1.0f); // Domyœlnie bia³y

    // Oblicz normalne dla ka¿dej œciany
    calculateNormals();
}

void IndexedCube::calculateNormals() {
    normals.resize(vertices.size(), 0.0f);

    // Dla ka¿dej œciany
    for (size_t i = 0; i < indices.size(); i += 3) {
        // Pobierz indeksy wierzcho³ków œciany
        unsigned int i1 = indices[i];
        unsigned int i2 = indices[i + 1];
        unsigned int i3 = indices[i + 2];

        // Pobierz wspó³rzêdne wierzcho³ków œciany
        glm::vec3 v1(vertices[i1 * 3], vertices[i1 * 3 + 1], vertices[i1 * 3 + 2]);
        glm::vec3 v2(vertices[i2 * 3], vertices[i2 * 3 + 1], vertices[i2 * 3 + 2]);
        glm::vec3 v3(vertices[i3 * 3], vertices[i3 * 3 + 1], vertices[i3 * 3 + 2]);

        // Oblicz wektor normalny do œciany
        glm::vec3 normal = glm::normalize(glm::cross(v2 - v1, v3 - v1));

        // Dodaj normalne do odpowiednich wierzcho³ków
        normals[i1 * 3] += normal.x;
        normals[i1 * 3 + 1] += normal.y;
        normals[i1 * 3 + 2] += normal.z;

        normals[i2 * 3] += normal.x;
        normals[i2 * 3 + 1] += normal.y;
        normals[i2 * 3 + 2] += normal.z;

        normals[i3 * 3] += normal.x;
        normals[i3 * 3 + 1] += normal.y;
        normals[i3 * 3 + 2] += normal.z;
    }

    // Znormalizuj wektory normalne
    for (size_t i = 0; i < normals.size(); i += 3) {
        glm::vec3 normal = glm::normalize(glm::vec3(normals[i], normals[i + 1], normals[i + 2]));
        normals[i] = normal.x;
        normals[i + 1] = normal.y;
        normals[i + 2] = normal.z;
    }
}

void IndexedCube::draw(float r, float g, float b) {
    glColor3f(r, g, b);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices.data());
    glNormalPointer(GL_FLOAT, 0, normals.data());
    glColorPointer(3, GL_FLOAT, 0, colors.data());

    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, indices.data());

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}
