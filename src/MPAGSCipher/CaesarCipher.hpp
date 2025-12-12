#ifndef CAESAR_CIPHER_HPP
#define CAESAR_CIPHER_HPP

#include <cstddef>
#include <string>
#include <vector>
#include "CipherMode.hpp"

/**
 * \file CaesarCipher.hpp
 * \brief Contains the declaration of the CaesarCipher class 
*/

/**
 * \class CaesarCipher
 * \brief A class representing the Caesar cipher
 */
class CaesarCipher {
public:
    explicit CaesarCipher(const std::size_t key);
    explicit CaesarCipher(const std::string key);
    std::string applyCipher(const std::string& inputText, const CipherMode mode) const;
private:
    std::size_t key_{0};
    // Create the alphabet container
    const std::vector<char> alphabet = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
};
#endif // CAESAR_CIPHER_HPP