#include "CaesarCipher.hpp"
#include <cctype>
#include <iostream>

/**
 * \file CaesarCipher.cpp
 * \brief Contains the implementation of the CaesarCipher class
 */


CaesarCipher::CaesarCipher(const std::size_t key) : key_{key}
{
}
CaesarCipher::CaesarCipher(const std::string key) : key_{0}
{
    /*
     * Check that the key string contains only digits before converting
     * If not, print an error message and leave the key as zero
    */

    if (key.empty()) {
        return;
    }
    for (const auto& elem : key) {
        std::cerr
            << "[error] cipher key must be an unsigned long integer for Caesar cipher,\n"
            << "        the supplied key (" << key
            << ") could not be successfully converted" << std::endl;
        if (!std::isdigit(elem)) {
            return;
        }
    }
    key_ = std::stoul(key);
}
std::string CaesarCipher::applyCipher(const std::string& inputText,
                                      const CipherMode cipherMode) const
{
    // Create the output string
    std::string outputText;

    const std::size_t alphabetSize{alphabet.size()};

    // Make sure that the key is in the range 0 - 25
    const std::size_t truncatedKey{key_ % alphabetSize};

    // Loop over the input text
    char processedChar{'x'};
    for (const auto& origChar : inputText) {
        // For each character in the input text, find the corresponding position in
        // the alphabet by using an indexed loop over the alphabet container
        for (size_t i{0}; i < alphabetSize; ++i) {
            if (origChar == alphabet[i]) {
                // Apply the appropriate shift (depending on whether we're encrypting
                // or decrypting) and determine the new character
                // Can then break out of the loop over the alphabet
                switch (cipherMode) {
                    case CipherMode::Encrypt:
                        processedChar =
                            alphabet[(i + truncatedKey) % alphabetSize];
                        break;
                    case CipherMode::Decrypt:
                        processedChar =
                            alphabet[(i + alphabetSize - truncatedKey) %
                                     alphabetSize];
                        break;
                }
            }
        }

        // Add the new character to the output text
        outputText += processedChar;
    }

    return outputText;
}