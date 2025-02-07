
#include <ansi.h>
#include <skill.h>
#include <action.h>

#define THIS_PERFORM    00021
#define PF_NAME        "推开尸体"

#define SUB_MP          10

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "［" PF_NAME "］\n推开其他玩家的尸体。\n"; 
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
                send_user( me, "%c%s", '!', sprintf( "推开尸体需要 %d 点法力。", mp ) );
                return 1;
        }
        me->add_mp(-mp);

        switch( get_d(me) )
        {
       case 1 : x ++;         break;
       case 2 : x ++;  y --;  break;
      default :        y --;  break;
       case 4 : x --;  y --;  break;
       case 5 : x --;         break;
       case 6 : x --;  y ++;  break;
       case 7 :        y ++;  break;
       case 8 : x ++;  y ++;  break;
        }

        if( get_block(z, x, y) & IS_CHAR_BLOCK ) return 1;

        who->add_to_scene( z, x, y, get_d(who) );

        write_user( me, ECHO "您将" + who->get_name() + "推开。" );
        write_user( who, ECHO "%s(%d)把您推开。", me->get_name(), me->get_number() );

        return 1;
}

// 函数：获取指令类型
int get_perform_type() { return ON_CHAR_7; }

// 函数：能否使用指令
void can_perform( object me )
{
        send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), 1, 0, PF_NAME );
}
