#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>

#define PF_FLAG        "11004"
#define PF_NAME        "�����޵й���ȭ"


// �����������(����)
int perform_action_npc( object me, object who )
{
        if( !CHAR_FIGHT_D->attack_action(me, who, 36) ) return 0;

        CHAR_FIGHT_D->attack_done(me, who, HIT_NONE);    // С��׼�� me
        if( !who ) return 2;    // ִ�гɹ�
        CHAR_FIGHT_D->attack_done(me, who, HIT_NONE);    // С��׼�� me

        return 1;    // ִ�гɹ�
}

int perform_done_npc( object me, object who )
{
        return 2;    // ִ�гɹ�
}