
#include <ansi.h>
#include <skill.h>
#include <action.h>

#define THIS_PERFORM    00022
#define PF_NAME        "抛开尸体"

#define SUB_MP          30

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "［" PF_NAME "］\n抛开其他玩家的尸体。\n"; 
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        int z, p, mp;

        if( !who->is_die() )
        {
                send_user(me, "%c%s", '!', "您只能把尸体推开。");
                return 1;
        }

        z = get_z(who);  x = get_x(who);  y = get_y(who);

        if( distance_between(who, me) > 1 )
        {
                send_user(me, "%c%s", '!', "您距离尸体太远了。");
                return 1;
        }

        mp = SUB_MP;    // 小心准备 level

        if( me->get_mp() < mp )
        {
                send_user( me, "%c%s", '!', sprintf( "扔出尸体需要 %d 点法力。", mp ) );
                return 1;
        }
        me->add_mp(-mp);

        if( !( p = get_valid_xy(z, x + random(10) - 5, y + random(10) - 5, IS_CHAR_BLOCK) ) ) return 1;

        x = p / 1000;  y = p % 1000;
        who->add_to_scene( z, x, y, get_front_xy( x, y, get_x(me), get_y(me) ) );
//      me->to_front_eachother(who);

        write_user( me, ECHO "您将" + who->get_name() + "扔了出去。" );
        write_user( who, ECHO "%s(%d)把您扔了出去。", me->get_name(), me->get_number() );

        return 1;
}

// 函数：获取指令类型
int get_perform_type() { return ON_CHAR_7; }

// 函数：能否使用指令
void can_perform( object me )
{
        send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), 1, 0, PF_NAME );
}
