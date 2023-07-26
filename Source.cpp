
#include <filesystem>
namespace fs = std::filesystem;

std::vector<fs::path> searchFile(const std::string& fileName, const fs::path& currentDir)
{
    std::vector<fs::path> foundPaths;

    for (const auto& entry : fs::directory_iterator(currentDir)) 
    {
        if (entry.is_directory()) 
        {
            std::vector<fs::path> subDirFiles = searchFile(fileName, entry.path());
            foundPaths.insert(foundPaths.end(), subDirFiles.begin(), subDirFiles.end());
        }
        else if (entry.is_regular_file() && entry.path().filename() == fileName) {
            foundPaths.push_back(entry.path());
        }
    }

    return foundPaths;
}


