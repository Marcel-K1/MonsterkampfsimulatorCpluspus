#pragma once


template<class T>
inline bool TryParse(std::string input, T& var)
{
    static const std::string ws(" \t\f\v\n\r");

    size_t pos = input.find_last_not_of(ws);

    if (pos != std::string::npos)
        input.erase(pos + 1);
    else input.clear();

    std::stringstream buffer(input);

    return buffer >> var && buffer.eof();
}
