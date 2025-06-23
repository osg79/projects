#include <bitset>
#include <iostream>

enum class Permissions
{
    READ = 0,
    WRITE = 1,
    EXECUTE = 2,
    ADMIN = 3,
};

int main()
{
    std::bitset<4U> permissions;

    // Grant READ and WRITE permissions
    permissions.set(static_cast<std::size_t>(Permissions::READ));
    permissions.set(static_cast<std::size_t>(Permissions::WRITE));
    std::cout << "Permissions: " << permissions << std::endl;

    // Test if WRITE permission has been granted
    if (permissions.test(static_cast<std::size_t>(Permissions::WRITE)))
    {
        std::cout << "Write permission has been granted" << std::endl;
    }
    else
    {
        std::cout << "Write permission has not been granted" << std::endl;
    }

    // Toggle EXECUTE permission
    permissions.flip(static_cast<std::size_t>(Permissions::EXECUTE));
    std::cout << "Permissions: " << permissions << std::endl;

    // Reset WRITE permission
    permissions.reset(static_cast<std::size_t>(Permissions::WRITE));
    std::cout << "Permissions: " << permissions << std::endl;

    // Set ADMIN permission
    permissions.set(static_cast<std::size_t>(Permissions::ADMIN));
    std::cout << "Permissions: " << permissions << std::endl;

    return 0;
}