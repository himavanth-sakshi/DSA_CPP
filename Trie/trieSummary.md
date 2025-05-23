# TRIE

## What is a Trie?
- A Trie is a special type of tree-based data structure that is used to store a 
dynamic set or associative array where the keys are usually strings.
- Each node in the Trie represents a character, and a path from the root to a node represents a prefix or a full word.

## Key Features of Trie:
Used for efficient retrieval of words in a dictionary.
Every node can have multiple children (typically 26 for lowercase English letters).
Faster than HashMap or BST for search operations when working with lots of strings and prefixes.

## Trie Structure:
Each node typically contains:
- A fixed-size array (like children[26]) or map for child pointers.
- A boolean flag isEndOfWord to indicate the end of a valid word.

## 1. TrieNode Structure

```plaintext
class TrieNode:
    data: character
    children: array of size 26 (for A-Z)
    isTerminal: boolean

    constructor(character ch):
        data = ch
        children = all NULL
        isTerminal = false
```

---

## 2. Trie Initialization

```plaintext
class Trie:
    root = new TrieNode('\0')
```

---

## 3. Insert a Word

**Function**: `insertWord(word)`  
**Initialization**: `current = root`

```plaintext
for each character ch in word:
    index = ch - 'A'

    if current.children[index] is NULL:
        current.children[index] = new TrieNode(ch)

    current = current.children[index]

current.isTerminal = true  // mark end of word
```

---

## 4. Search a Word

**Function**: `searchWord(word)`  
**Initialization**: `current = root`

```plaintext
for each character ch in word:
    index = ch - 'A'

    if current.children[index] is NULL:
        return false

    current = current.children[index]

return current.isTerminal
```

---

## 5. Starts With (Prefix Search)

**Function**: `startsWith(prefix)`  
**Initialization**: `current = root`

```plaintext
for each character ch in prefix:
    index = ch - 'A'

    if current.children[index] is NULL:
        return false

    current = current.children[index]

return true
```

---

## 6. Remove a Word

**Function**: `removeWord(node, word, depth = 0)`

```plaintext
if node is NULL:
    return NULL

if depth == word.length:
    node.isTerminal = false

    if node has no children:
        delete node
        return NULL

    return node

index = word[depth] - 'A'
node.children[index] = removeWord(node.children[index], word, depth + 1)

if node has no children and node.isTerminal == false:
    delete node
    return NULL

return node
```

---

## 7. Check if a Node is Empty

**Function**: `isEmpty(node)`

```plaintext
for each child in node.children:
    if child is not NULL:
        return false

return true
```

---

## 8. Time Complexity Summary

| Operation    | Time Complexity | Description                   |
|--------------|------------------|-------------------------------|
| Insert       | O(L)             | Add a word (L = word length)  |
| Search       | O(L)             | Find a complete word          |
| StartsWith   | O(L)             | Check prefix existence        |
| Remove       | O(L)             | Delete a word safely          |

---

📌 Use this guide while solving string problems, autocomplete features, and dictionary-based lookups.
