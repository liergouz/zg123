//����������Ϸʱ�䣬��ĳЩ�������
#include <ansi.h>

// �����������
int main( object me, string arg )
{
	int year,mon,day,hour,min,sec;
	string tmp;
	
        if( !is_gm2(me) && !is_god(me) ) 
        {
                notify( "��û���㹻��Ȩ�ޡ�" );
		return 1;
        }
        if ( !arg )
        {
        	tell_user(me,"��Ϸ�Ļʱ���ǣ�%s",short_time(get_party_time()));
        	tell_user(me,"���õ�ָ���ʽ�ǣ�/set_party_time ��-��-�� ʱ:��:��");
        	return 1;	
        }
	if ( sscanf(arg,"%d-%d-%d %d:%d:%d",year,mon,day,hour,min,sec) != 6 )
	{
		send_user(me,"%c%s",'!',"����ĸ�ʽ");
        	tell_user(me,"��Ϸ�Ļʱ���ǣ�%s",short_time(get_party_time()));
        	tell_user(me,"���õ�ָ���ʽ�ǣ�/set_party_time ��-��-�� ʱ:��:��");
		return 1;
	}
	tell_user(me,"��Ϸ�Ļʱ������Ϊ��%s",short_time(set_party_time(year,mon,day,hour,min,sec)));
	return 1;
	
}