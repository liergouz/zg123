#include <ansi.h>

// �����������
int main( object me, string arg )
{
	string result;
        object who;
        string type;
        int id;
        
        if( gone_time( me->get_time("black") ) < 1 )
        {
                me->set_time( "black", time() );
                return 1;
        }
        me->set_time( "black", time() );

        if( sscanf( arg, "%s %d %s", type, id, arg ) ) 
        {
		switch(type)
		{
		case "+":
			me->add_black(sprintf("%d",id), arg);
			break;
		case "-":
			me->del_black(sprintf("%d",id));
			break;
		}		
        }
        else notify("��ʽ����");
	
        return 1;
}
