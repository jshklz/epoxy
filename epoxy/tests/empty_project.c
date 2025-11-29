#include <EPOXY.h>
#include <assert.h>


i32 main(void)
{
    EPOXY_Init();
    
    /////////////////////////////////////////////////////////////////
    OS_App* app = OS_ConstructApp("Hello, EPOXY!", 
                                  OS_AppDefault,
                                  OS_AppDefault,
                                  OS_AppStyleDefault);
    assert(app && "Failed to create window");
    /////////////////////////////////////////////////////////////////
    
    GFX_Renderer* renderer = GFX_CreateRenderer(app);
    assert(renderer && "Failed to create renderer");
    
    while (app->running)
    {
        OS_PollEvents(app);
        
        GFX_Present(renderer);
    }
    
    EPOXY_Destroy();
    return 0;
}


