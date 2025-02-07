
#include <ansi.h>
#include <music.h>

#define TASK_BONUS      100

string get_name();

// ������ʹ����Ʒ
int is_task_item() { return 1; }

// ��������λ����
void reset() { }

// ���������轱��
void give_bonus( object who )
{
	int exp;
        if( who->is_npc() ) return;
	
	exp = TASK_BONUS * who->get_online_rate()/100;
        who->add_exp( exp );

        who->add_log("&task", exp);
        who->add_log("#task", 1);

        send_user( who, "%c%w", 0x0d, MUSIC_TASK );
        write_user( who, ECHO "�����%s��ʹ�������� %+d��", get_name(), exp );
}
