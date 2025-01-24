#include <Core/Logger.h>
#include <Core/Asserts.h>

int main(void)
{
    SDEBUG("Hello %d\n", 1);
    SWARN("Hello %d\n", 1);
    STRACE("Hello %d\n", 1);
    SINFO("Hello %d\n", 1);
    //SFATAL("Hello %d\n", 1);

    const char* message = "TEST ASSERT!";

    SASSERT_MSG(1 == 0, message);

    SINFO("Check for GitHub Actions to Run!\n");

    return 0;
}