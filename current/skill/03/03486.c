
// 隐含技能  TIPS:[PF_NONE]

#include <ansi.h>
#include <skill.h>

#define THIS_SKILL      0348
#define THIS_PERFORM    03486
#define PF_START       "03486"
#define PF_NAME        "九死一生"

#define SKILL_LEVEL     80

int SKILL_LEVEL_SQUARE = SKILL_LEVEL * (SKILL_LEVEL - 1);

// 函数：获取描述
string get_desc( object me )
{
        int level = me->get_skill(THIS_SKILL);
        return sprintf( "［" PF_NAME "］被动技能，生命值低于 10％时自动生效，持续补满玩家的元气，%s%d 级可用\n",
                level < SKILL_LEVEL ? HIR : "", SKILL_LEVEL );
}

// 函数：获取描述(持续)
string get_loop_desc( object me )
{
        if( me->get_perform(PF_START) )
                return sprintf( PF_NAME "：\n　　持续补满元气。\n" );
        else    return sprintf( PF_NAME "\n" );
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        return 1;
}

// 函数：获取特技类型
int get_perform_type() { return ON_ME; }

// 函数：能否使用特技
void can_perform( object me )
{
        send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, 0, 1, 0, PF_NAME );
}
