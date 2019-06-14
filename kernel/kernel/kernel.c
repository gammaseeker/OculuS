#include <stdio.h>
#include <kernel/tty.h>

void kernel_main(void) 
{
    /* Initialize terminal interface */
    terminal_initialize();
 
    printf("\
                                                    `-.\n\
                                                      .`\n\
                                                   _.`.`\n\
                                               _.-` .`\n\
                                       ___.---` _.-`\n\
                               __..---`___..---`\n\
                      _...--.-`   _.--`\n\
                  _.-`.-`.-`  _.-`\n\
               .-` .`  .`   .`\n\
    .         /   /   /    /                    .\n\
   \\`-.._    |  |    \\    `.              _..-`/\n\
   .'-.._ ``--.._\\     `. -- `.      _..-``  _..-`.\n\
   `_    _       `-. .`        `. .-`      _    _`\n\
     `.``           .            \\          ``.`\n\
      `-.-'    _   .              :   _   `-.-`\n\
        `..-..'    ;       .` `.  '    `..-..`\n\
            /      .      : .-. : :        \\\n\
            `._     \\     ;( O ) /      _.`\n\
     LGB       `-._.'`.    .`-'.' `._.-'\n\
                       `-....-` \n\
Welcome to OculuS");

    printf("Hello, kernel world!\n");
}
