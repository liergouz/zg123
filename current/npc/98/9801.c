
#include <npc.h>
#include <equip.h>

inherit "/inh/npc/task";

// 函数：构造处理
void create()
{
        set_name( "嫪毒" );
        NPC_EQUIP_D->init_figure( this_object(), MINISTER, MALE, 30 );
        set_char_picid(4144);    
        setup();
}

// 函数：获取装备代码
int get_weapon_code() { return UNARMED; }
