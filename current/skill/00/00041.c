
#include <ansi.h>
#include <skill.h>

#define THIS_PERFORM    00041
#define PF_NAME        "׷�麷��"

#define SUB_MP          10

// ��������ȡ����
string get_desc( object me ) 
{ 
        return "��" PF_NAME "��\n׷��ʦү�˷������Ŀ�꺷�˷�λ��\n"; 
}

// 
void check_target(object me, object npc);

// �����������
int main( object me, object who, int x, int y, string arg )
{
        object npc, *targets;
        string id, result;
        int z, x0, y0, dx, dy;
        int i, mp, size, flag;
        
        flag = 0;
        if (npc=me->get("target"))
        {
        	if ( npc->get("user")==me->get_number() )
                {
        		check_target(me, npc);
        		flag = 1;
        	}
        }
        if (targets=me->get("targets"))
        {
        	targets -= ({ 0 });
        	me->set("targets", targets);
        	size = sizeof(targets);
        	for (i=0;i<size;i++)
        		if ( objectp(targets[i]) && (targets[i]->get("user")==me->get_number()) )
                        {        		        
        			check_target(me, targets[i]);
        			flag = 1;
        		}
        }
        if (flag==0)
        {                
                if(    !stringp( id = me->get_task("robber") ) 
                ||   !( npc = find_char(id) ) || !npc->is_robber() )    // 30 ����
                {
                        send_user(me, "%c%s", '!', "��û����ȡ��Ҫ׷�����������");
                        return 1;
                }
                else
                        check_target(me, npc);
        }        
}                

void check_target(object me, object npc)
{
        string id, result;
        int z, x0, y0, dx, dy, x, y;
        int i, mp;
        z = get_z(npc);  x = get_x(npc);  y = get_y(npc);

        if( get_z(me) != z )
        {
                send_user( me, "%c%s", '!', sprintf( "%s���ڱ������ڡ�", npc->get_name() ) );
                return ;
        }

        mp = SUB_MP;    // С��׼�� level

        if( me->get_mp() < mp )
        {
                send_user(me, "%c%s", '!', sprintf( "׷����Ҫ %d �㷨����", mp ) );
                return ;
        }

        x0 = get_x(me);  y0 = get_y(me);
        dx = abs(x0 - x);  dy = abs(y0 - y);

        if( dx <= 20 && dy <= 20 )
                result = sprintf( "����Χ��%s", PF_NO_00031->get_direction(x0, y0, x, y) );
        else if( dx <= 40 && dy <= 40 )
                result = sprintf( "��������%s", PF_NO_00031->get_direction(x0, y0, x, y) );
        else if( dx <= 60 && dy <= 60 )
                result = sprintf( "�����ܽ���%s", PF_NO_00031->get_direction(x0, y0, x, y) );
        else if( dx <= 80 && dy <= 80 )
                result = sprintf( "������Զ��%s", PF_NO_00031->get_direction(x0, y0, x, y) );
        else if( dx <= 100 && dy <= 100 )
                result = sprintf( "������Զ��%s", PF_NO_00031->get_direction(x0, y0, x, y) );
        else    result = sprintf( "������Զ��%s", PF_NO_00031->get_direction(x0, y0, x, y) );

        tell_user( me, "��׷�ٵ�%s��%s��", npc->get_name(), result );    // write_user

        me->add_mp(-mp);
}

// ��������ȡָ������
int get_perform_type() { return ON_ME_7; }

// �������ܷ�ʹ��ָ��
void can_perform( object me )
{
        send_user( me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), 1, 0, PF_NAME );
}
