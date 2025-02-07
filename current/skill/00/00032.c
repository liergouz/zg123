
#include <ansi.h>
#include <skill.h>

#define THIS_PERFORM    00032
#define PF_NAME        "��ʹ����Ʒ"

#define TASK_TIME       1800

// ��������ȡ����
string get_desc( object me ) 
{ 
        return "��" PF_NAME "��\n׷�����ִ塢�Ľ���Ұ��һ������ʹ����Ʒ�ķ�λ��\n"; 
}

// �����������
int main( object me, object who, int x, int y, string arg )
{
        object *task, map, item;
        string result, result2;
        int z, x0, y0, dx, dy, time, i, size;

        if( !arg || arg == "" )
        {
                if( size = sizeof( task = TASK_D->get_task_item() ) )
                {
                        result = "����ʹ����Ʒ�б�\n";
                        for( i = 0; i < size; i ++ )
                        {
                                if( objectp( task[i] ) )
                                {
                                        if( environment( task[i] ) )
                                        {
                                                result2 = sprintf( "%s(�����С���)\nCLOSE\n", task[i]->get_name() );
                                        }
                                        else
                                        {
                                                z = get_z( task[i] );
                                                map = get_map_object(z);

                                                if( objectp(map) ) 
                                                        result2 = sprintf( "%s(%s)%s\npf2 00032.%d\n", 
                                                                task[i]->get_name(), map->get_name(), z == get_z(me) ? "��" : "", i + 1 );
                                                else    result2 = "(�����)\nCLOSE\n";
                                        }
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

                        result = sprintf( "Ҫ��%s֮�����ʹ����Ʒ����\n"
                                ESC "�����ȴ���\nCLOSE\n", result );
                }

                send_user( me, "%c%c%w%s", ':', 3, 6009,result );
        }
        else if( x = to_int(arg) )
        {
                if( !objectp( item = TASK_D->get_task_item_2(x) ) ) return 1;
                if( environment(item) ) return 1;

                z = get_z(item);  x = get_x(item);  y = get_y(item);
                if( !objectp( map = get_map_object(z) ) ) return 1;

                if( z == get_z(me) )
                {
                        x0 = get_x(me);  y0 = get_y(me);
                        dx = abs(x0 - x);  dy = abs(y0 - y);
                        if( dx <= 50 && dy <= 50 )
                                result = sprintf( "��������%s��", PF_NO_00031->get_direction(x0, y0, x, y) );
                        if( dx <= 100 && dy <= 100 )
                                result = sprintf( "�����ȽϽ���%s��", PF_NO_00031->get_direction(x0, y0, x, y) );
                        else    result = sprintf( "�����Ƚ�Զ��%s��", PF_NO_00031->get_direction(x0, y0, x, y) );
                }
                else
                {
                        x0 = get_map_max_x(z) / 2;  y0 = get_map_max_y(z) / 2;
                        dx = abs(x0 - x);  dy = abs(y0 - y);
                        if( dx <= 50 && dy <= 50 )
                                result = sprintf( "%s�м��%s��", map->get_name(), PF_NO_00031->get_direction(x0, y0, x, y) );
                        if( dx <= 100 && dy <= 100 )
                                result = sprintf( "%s�ȽϽ���%s��", map->get_name(), PF_NO_00031->get_direction(x0, y0, x, y) );
                        else    result = sprintf( "%s�Ƚ�Զ��%s��", map->get_name(), PF_NO_00031->get_direction(x0, y0, x, y) );
                }
                send_user( me, "%c%c%w%s", ':', 3, 6009,sprintf( "ʹ����Ʒ" HIY "%s" NOR "�����ڣ�\n\n%s\n", item->get_name(), result ));
        }

        return 1;
}

// ��������ȡָ������
int get_perform_type() { return ON_ME_7; }

// �������ܷ�ʹ��ָ��
void can_perform( object me )
{
        send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), 1, 0, PF_NAME );
}
