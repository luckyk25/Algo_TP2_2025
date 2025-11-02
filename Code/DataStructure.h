#pragma once
#include "Node.h"

namespace TestsCode
{
  class TestsQueue;
  class TestsStack;
}
/**
 * @class DataStructure
 * @brief Classe de base abstraite pour diverses structures de données.
 *
 * La classe DataStructure fournit une interface commune pour différentes structures
 * de données, avec des fonctionnalités de base pour la gestion des nœuds.
 */

class DataStructure
{
public:
  /**
   * @brief Constructeur par défaut.
   *
   * Initialise un objet DataStructure avec le premier nœud à nullptr.
   */
  DataStructure();

  /**
   * @brief Constructeur de copie.
   *
   * @param src Référence constante à un objet DataStructure à copier.
   *
   * Crée une copie profonde de l'objet src, y compris ses nœuds.
   */
  DataStructure(const DataStructure& src);

  /**
   * @brief Destructeur virtuel.
   *
   * Libère les ressources allouées par l'objet DataStructure.
   */
  virtual ~DataStructure();

  /**
   * @brief Affiche le contenu de la structure de données.
   *
   * Méthode pure virtuelle qui doit être implémentée par les classes dérivées.
   */
  virtual void display() const = 0;

  /**
   * @brief Renvoie la taille de la structure de données.
   *
   * @return Le nombre d'éléments dans la structure de données.
   */
  unsigned int size() const;

  /**
   * @brief Vérifie si la structure de données est vide.
   *
   * @return true si la structure de données est vide, sinon false.
   */
  virtual bool isEmpty() const;

protected:
  /**
   * @brief Renvoie un pointeur constant vers le premier nœud.
   *
   * @return Pointeur constant vers le premier nœud.
   */
  const Node* getFirstNode() const;

  /**
   * @brief Renvoie un pointeur vers le premier nœud.
   *
   * @return Pointeur vers le premier nœud.
   */
  Node* getFirstNode();

  /**
   * @brief Définit le premier nœud de la structure de données.
   *
   * @param node Pointeur vers le nouveau premier nœud.
   */
  void setFirstNode(Node* node);

private:
  Node* firstNode; /**< Pointeur vers le premier nœud de la structure de données. */

  friend TestsCode::TestsQueue;
  friend TestsCode::TestsStack;
};

