
#include <npc.h>
#include <equip.h>

inherit "/inh/npc/task";

// ���������촦��
void create()
{
        set_name( "����" );
        NPC_EQUIP_D->init_figure( this_object(), MINISTER, MALE, 30 );
        set_char_picid(8011);    
        setup();
}

// ��������ȡװ������
int get_weapon_code() { return UNARMED; }
