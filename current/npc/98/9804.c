
#include <npc.h>
#include <equip.h>

inherit "/inh/npc/task";

// 函数：构造处理
void create()
{
        set_name( "李兑" );
        NPC_EQUIP_D->init_figure( this_object(), MARSHAL, MALE, 30 );
        set_char_picid(4133);    
        setup();
}

// 函数：获取装备代码
int get_weapon_code() { return BLADE; }
