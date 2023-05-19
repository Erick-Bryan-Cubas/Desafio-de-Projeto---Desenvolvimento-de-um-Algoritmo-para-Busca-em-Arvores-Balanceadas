# Árvore AVL em C++

Este repositório contém uma implementação de uma árvore AVL (Adelson-Velsky e Landis) em C++. A árvore AVL é uma árvore binária de busca autoequilibrada, onde a diferença de altura entre as subárvores esquerda e direita de qualquer nó é no máximo 1. Essa propriedade garante que a árvore permaneça equilibrada após operações de inserção e remoção, evitando a formação de árvores degeneradas e garantindo uma busca eficiente.

## Implementação

O código cria uma classe `AVLTree` que utiliza a classe `Node` para representar cada nó da árvore. A classe `AVLTree` possui métodos para inserir elementos, equilibrar a árvore e realizar percurso em ordem.

### Rotação à esquerda e à direita

As rotações são operações fundamentais para manter a árvore equilibrada. A rotação à esquerda transforma a disposição dos nós à direita em disposição à esquerda. A rotação à direita faz o oposto, transformando a disposição dos nós à esquerda em disposição à direita.

### Inserção

A inserção na árvore AVL segue os mesmos passos da inserção em uma árvore binária de busca comum. No entanto, após a inserção, a árvore é equilibrada usando rotações à esquerda e à direita, conforme necessário.

### Exemplo de uso

O exemplo a seguir demonstra como inserir elementos na árvore e imprimir a árvore usando percurso em ordem:

```cpp
#include "AVLTree.h"

int main() {
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    std::cout << "In-order traversal of the constructed AVL tree is: ";
    tree.inorder();

    return 0;
}
```

## Por que usar árvores AVL?

A maioria das operações em BST (por exemplo, busca, máximo, mínimo, inserção, exclusão, etc.) levam tempo O(h), onde h é a altura da BST. O custo dessas operações pode se tornar O(n) para uma árvore binária inclinada. Se garantirmos que a altura da árvore permaneça O(log(n)) após cada inserção e exclusão, podemos garantir um limite superior de O(log(n)) para todas essas operações. A altura de uma árvore AVL é sempre O(log(n)), onde n é o número de nós na árvore.