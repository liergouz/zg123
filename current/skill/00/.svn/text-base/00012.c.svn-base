
#include <ansi.h>
#include <skill.h>

#define THIS_PERFORM    00012
#define PF_NAME        "摆摊"

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "［" PF_NAME "］\n在周国的摆摊区摆摊卖东西。\n"; 
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        me->force_me("store");    // 发出 store 命令

        return 1;
}

// 函数：获取指令类型
int get_perform_type() { return ON_ME_7; }

// 函数：能否使用指令
void can_perform( object me )
{
        send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), 1, 0, PF_NAME );
}
