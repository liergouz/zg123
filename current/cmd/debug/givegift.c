
#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

// �����������
int main( object me, string arg )
{
	object who;
        int i, size, a1, a2, a3, a4;
        if( is_player(me) ) 
        {
                notify( "��û���㹻��Ȩ�ޡ�" );
		return 1;
        }
        if( arg && !( who = find_any_char(arg) ) )
        {
                notify( "���޷��ҵ�����ˡ�" );
		return 1;
        }        
        if (who->get_save("testbonus"))
        {
                notify( "�Է��Ѿ������˽���" );
		return 1;        	
        }
        who->set_save("testbonus", 1);
        who->add_gift_point(who->get_level()*2);	        		
	tell_user(me, sprintf("������%s(%d)�Ľ���", who->get_name(), who->get_number()));	        		
        return 1;
}
