
#include <ansi.h>
#include <skill.h>

#define THIS_PERFORM    00031
#define PF_NAME        "��ʹ������"

#define TASK_TIME       1800

// ��������ȡ����
string get_desc( object me ) 
{ 
        return "��" PF_NAME "��\n׷�����ִ塢�Ĺȡ���Ϫһ������ʹ������ķ�λ��\n"; 
}

// �����������
int main( object me, object who, int x, int y, string arg )
{
        object *task, map;
        string result, result2;
        int z, x0, y0, dx, dy, time, i, size;

        if( !arg || arg == "" )
        {
                if( size = sizeof( task = TASK_D->get_task_npc() ) )
                {
                        result = "����ʹ�������б��������ɣ�\n";
                        for( i = 0; i < size; i ++ )
                        {
                                if( objectp( task[i] ) )
                                {
                                        z = get_z( task[i] );
                                        map = get_map_object(z);

                                        if( objectp(map) ) 
                                                result2 = sprintf( "%s(%s)%s\npf2 00031.%d\n", 
                                                        task[i]->get_name(), map->get_name(), z == get_z(me) ? "��" : "", i + 1 );
                                        else    result2 = "(�����)\nCLOSE\n";
                                }
                                else    result2 = "(�����)\nCLOSE\n";

                                result = sprintf( "%s" ESC "%s", result, result2 );
                        }
                }
                else
                {
                        time = ( time() + TASK_TIME ) / TASK_TIME * TASK_TIME - time();

                        result = "";
                        if( time / 60 ) result += sprintf( " %d ��", time / 60 );
                        result += sprintf( " %d ��", time % 60 );

                        result = sprintf( "Ҫ��%s֮�����ʹ����������\n"
                                ESC "�����ȴ���\nCLOSE\n", result );
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
                                result = sprintf( "����Χ��%s��", PF_NO_00031->get_direction(x0, y0, x, y) );
                        else if( dx <= 40 && dy <= 40 )
                                result = sprintf( "��������%s��", PF_NO_00031->get_direction(x0, y0, x, y) );
                        else if( dx <= 60 && dy <= 60 )
                                result = sprintf( "�����ܽ���%s��", PF_NO_00031->get_direction(x0, y0, x, y) );
                        else if( dx <= 80 && dy <= 80 )
                                result = sprintf( "������Զ��%s��", PF_NO_00031->get_direction(x0, y0, x, y) );
                        else if( dx <= 100 && dy <= 100 )
                                result = sprintf( "������Զ��%s��", PF_NO_00031->get_direction(x0, y0, x, y) );
                        else    result = sprintf( "������Զ��%s��", PF_NO_00031->get_direction(x0, y0, x, y) );
                }
                else
                {
                        x0 = get_map_max_x(z) / 2;  y0 = get_map_max_y(z) / 2;
                        dx = abs(x0 - x);  dy = abs(y0 - y);

                        if( dx <= 20 && dy <= 20 )
                                result = sprintf( "%s������Χ��%s��", map->get_name(), PF_NO_00031->get_direction(x0, y0, x, y) );
                        else if( dx <= 40 && dy <= 40 )
                                result = sprintf( "%s���ĸ�����%s��", map->get_name(), PF_NO_00031->get_direction(x0, y0, x, y) );
                        else if( dx <= 60 && dy <= 60 )
                                result = sprintf( "��%s���ĺܽ���%s��", map->get_name(), PF_NO_00031->get_direction(x0, y0, x, y) );
                        else if( dx <= 80 && dy <= 80 )
                                result = sprintf( "��%s���Ĳ�Զ��%s��", map->get_name(), PF_NO_00031->get_direction(x0, y0, x, y) );
                        else if( dx <= 100 && dy <= 100 )
                                result = sprintf( "��%s���ĺ�Զ��%s��", map->get_name(), PF_NO_00031->get_direction(x0, y0, x, y) );
                        else    result = sprintf( "��%s���ļ�Զ��%s��", map->get_name(), PF_NO_00031->get_direction(x0, y0, x, y) );
                }
                
                send_user( me, "%c%c%w%s", ':', 3, 5501, sprintf( "ʹ������" HIR "%s" NOR "�����ڣ�\n\n%s\n", who->get_name(), result ) );
        }

        return 1;
}

// ��������ȡ�����ִ�
string get_direction( int x0, int y0, int x1, int y1 )
{
        int dx, dy, xy;

        dx = x1 - x0;  dy = y1 - y0;

        if( dx > 0 )
        {
                if( dy > 0 )    // ��һ����
                {
                        xy = abs( dy * 1000 / dx );
                        if( xy < 1000 / 3 ) return "����";
                        else if( xy < 3000 ) return "������";
                        else return "����";
                }
                else if( dy < 0 )    // ��������
                {
                        xy = abs( dy * 1000 / dx );
                        if( xy < 1000 / 3 ) return "����";
                        else if( xy < 3000 ) return "���Ϸ�";
                        else return "�Ϸ�";
                }
                else    return "����";
        }
        else if( dx < 0 )
        {
                if( dy > 0 )    // �ڶ�����
                {
                        xy = abs( dy * 1000 / dx );
                        if( xy < 1000 / 3 ) return "����";
                        else if( xy < 3000 ) return "������";
                        else return "����";
                }
                else if( dy < 0 )    // ��������
                {
                        xy = abs( dy * 1000 / dx );
                        if( xy < 1000 / 3 ) return "����";
                        else if( xy < 3000 ) return "���Ϸ�";
                        else return "�Ϸ�";
                }
                else    return "����";
        }
        else
        {
                if( dy > 0 ) return "����";
                else if( dy < 0 ) return "�Ϸ�";
                else return "��Χ";
        }
}

// ��������ȡָ������
int get_perform_type() { return ON_ME_7; }

// �������ܷ�ʹ��ָ��
void can_perform( object me )
{
        send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), 1, 0, PF_NAME );
}
