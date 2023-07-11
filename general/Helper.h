#pragma once
#include <vector>
#include <unordered_set>
#include <algorithm>

// J'utilise cette file pour definir mes helper functions

template <typename T>
inline bool isElementInVector(const std::vector<T>& vec, const T& element)
{
    for (const auto& item : vec)
    {
        if (item == element)
        {
            return true;
        }
    }
    return false;
}

template <typename T>
inline void deleteElementFromVector(std::vector<T>& vec, const T& element, bool keep_order=false)
{
    auto it = std::find(vec.begin(), vec.end(), element); 
    if (it != vec.end()){
        if(keep_order){
            vec.erase(std::remove(vec.begin(), vec.end(), element), vec.end());
        }
        else{
            std::swap(*it, vec.back());
            vec.pop_back();
        }
    }
}

template <typename T>
inline void deleteDuplicatesFromVector(std::vector<T>& vec)
{
    std::unordered_set<T> uniqueElements;
    std::vector<T> result;

    for (const auto& element : vec) {
        if (uniqueElements.insert(element).second) {
            result.push_back(element);
        }
    }
    vec = std::move(result);
}