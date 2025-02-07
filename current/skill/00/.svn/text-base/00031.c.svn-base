
#include <ansi.h>
#include <skill.h>

#define THIS_PERFORM    00031
#define PF_NAME        "查使命人物"

#define TASK_TIME       1800

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "［" PF_NAME "］\n追查新手村、幽谷、清溪一带出现使命人物的方位。\n"; 
}

// 函数：命令处理
int main( object me, object who, int x, int y, string arg )
{
        object *task, map;
        string result, result2;
        int z, x0, y0, dx, dy, time, i, size;

        if( !arg || arg == "" )
        {
                if( size = sizeof( task = TASK_D->get_task_npc() ) )
                {
                        result = "现有使命人物列表，请组队完成：\n";
                        for( i = 0; i < size; i ++ )
                        {
                                if( objectp( task[i] ) )
                                {
                                        z = get_z( task[i] );
                                        map = get_map_object(z);

                                        if( objectp(map) ) 
                                                result2 = sprintf( "%s(%s)%s\npf2 00031.%d\n", 
                                                        task[i]->get_name(), map->get_name(), z == get_z(me) ? "√" : "", i + 1 );
                                        else    result2 = "(已完成)\nCLOSE\n";
                                }
                                else    result2 = "(已完成)\nCLOSE\n";

                                result = sprintf( "%s" ESC "%s", result, result2 );
                        }
                }
                else
                {
                        time = ( time() + TASK_TIME ) / TASK_TIME * TASK_TIME - time();

                        result = "";
                        if( time / 60 ) result += sprintf( " %d 分", time / 60 );
                        result += sprintf( " %d 秒", time % 60 );

                        result = sprintf( "要等%s之后才有使命人物任务。\n"
                                ESC "继续等待。\nCLOSE\n", result );
                }

                send_user( me, "%c%c%w%s", ':', 3, 5501, result );
        }
        else if( x = to_int(arg) )
        {
                if( !objectp( who = TASK_D->get_task_npc_2(x) ) ) return 1;

                z = get_z(who);  x = get_x(who);  y = get_y(who);
                if( !objectp( map = get_map_object(z) ) ) return 1;

                if( z == get_z(me) )
                {
                        x0 = get_x(me);  y0 = get_y(me);
                        dx = abs(x0 - x);  dy = abs(y0 - y);

                        if( dx <= 20 && dy <= 20 )
                                result = sprintf( "您周围的%s。", PF_NO_00031->get_direction(x0, y0, x, y) );
                        else if( dx <= 40 && dy <= 40 )
                                result = sprintf( "您附近的%s。", PF_NO_00031->get_direction(x0, y0, x, y) );
                        else if( dx <= 60 && dy <= 60 )
                                result = sprintf( "离您很近的%s。", PF_NO_00031->get_direction(x0, y0, x, y) );
                        else if( dx <= 80 && dy <= 80 )
                                result = sprintf( "离您不远的%s。", PF_NO_00031->get_direction(x0, y0, x, y) );
                        else if( dx <= 100 && dy <= 100 )
                                result = sprintf( "离您很远的%s。", PF_NO_00031->get_direction(x0, y0, x, y) );
                        else    result = sprintf( "离您极远的%s。", PF_NO_00031->get_direction(x0, y0, x, y) );
                }
                else
                {
                        x0 = get_map_max_x(z) / 2;  y0 = get_map_max_y(z) / 2;
                        dx = abs(x0 - x);  dy = abs(y0 - y);

                        if( dx <= 20 && dy <= 20 )
                                result = sprintf( "%s中心周围的%s。", map->get_name(), PF_NO_00031->get_direction(x0, y0, x, y) );
                        else if( dx <= 40 && dy <= 40 )
                                result = sprintf( "%s中心附近的%s。", map->get_name(), PF_NO_00031->get_direction(x0, y0, x, y) );
                        else if( dx <= 60 && dy <= 60 )
                                result = sprintf( "离%s中心很近的%s。", map->get_name(), PF_NO_00031->get_direction(x0, y0, x, y) );
                        else if( dx <= 80 && dy <= 80 )
                                result = sprintf( "离%s中心不远的%s。", map->get_name(), PF_NO_00031->get_direction(x0, y0, x, y) );
                        else if( dx <= 100 && dy <= 100 )
                                result = sprintf( "离%s中心很远的%s。", map->get_name(), PF_NO_00031->get_direction(x0, y0, x, y) );
                        else    result = sprintf( "离%s中心极远的%s。", map->get_name(), PF_NO_00031->get_direction(x0, y0, x, y) );
                }
                
                send_user( me, "%c%c%w%s", ':', 3, 5501, sprintf( "使命人物" HIR "%s" NOR "现在在：\n\n%s\n", who->get_name(), result ) );
        }

        return 1;
}

// 函数：获取方向字串
string get_direction( int x0, int y0, int x1, int y1 )
{
        int dx, dy, xy;

        dx = x1 - x0;  dy = y1 - y0;

        if( dx > 0 )
        {
                if( dy > 0 )    // 第一象限
                {
                        xy = abs( dy * 1000 / dx );
                        if( xy < 1000 / 3 ) return "东方";
                        else if( xy < 3000 ) return "东北方";
                        else return "北方";
                }
                else if( dy < 0 )    // 第四象限
                {
                        xy = abs( dy * 1000 / dx );
                        if( xy < 1000 / 3 ) return "东方";
                        else if( xy < 3000 ) return "东南方";
                        else return "南方";
                }
                else    return "东方";
        }
        else if( dx < 0 )
        {
                if( dy > 0 )    // 第二象限
                {
                        xy = abs( dy * 1000 / dx );
                        if( xy < 1000 / 3 ) return "西方";
                        else if( xy < 3000 ) return "西北方";
                        else return "北方";
                }
                else if( dy < 0 )    // 第三象限
                {
                        xy = abs( dy * 1000 / dx );
                        if( xy < 1000 / 3 ) return "西方";
                        else if( xy < 3000 ) return "西南方";
                        else return "南方";
                }
                else    return "西方";
        }
        else
        {
                if( dy > 0 ) return "北方";
                else if( dy < 0 ) return "南方";
                else return "周围";
        }
}

// 函数：获取指令类型
int get_perform_type() { return ON_ME_7; }

// 函数：能否使用指令
void can_perform( object me )
{
        send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), 1, 0, PF_NAME );
}
