
#include <ansi.h>
#define COUND_d "/sys/sys/count"

string get_type_word(int type)
{
	switch(type)
	{
	case 0: return "��Ѫ";
	case 1: return "����";
	case 2: return "����";
	case 3: return "����";
	case 4: return "����";
	case 5: return "����";
	default: return "����";
	}
}

string get_fam_word(int type)
{
	switch(type)
	{
	case 0: return "������";
	case 1: return "�һ�Դ";
	case 2: return "��ɽ";
	case 3: return "������";
	case 4: return "����";
	case 5: return "éɽ";
	case 6: return "����ɽ";
	default: return "������";
	}
}

// �����������
int main( object me, string arg )
{
        object *zombie, soldier;
        string cmd1, cmd2, cmd3, cmd4, cmd5, cmd6, cmd7, cmd8;
        int type, type2, index, value;

        if( me != this_player(1) || is_player(me) ) 
        {
                notify( "��û���㹻��Ȩ�ޡ�" );
		return 1;
        }

        if( !arg )
        {
                send_user( me, "%c%s", ':', "����鿴���๫ʽ��\n"
                        ESC "��Ѫ��ʽ\nenergy 0\n"
                        ESC "������ʽ\nenergy 1\n"
                        ESC "������ʽ\nenergy 2\n"
                        ESC "������ʽ\nenergy 3\n"
                        ESC "������ʽ\nenergy 4\n"
                        ESC "������ʽ\nenergy 5\n"
                        ESC "���ݹ�ʽ\nenergy 6\n"                                        
                        ESC "�뿪\nCLOSE\n" );
                return 1;
        }
        if (sscanf(arg, "%d %d %d %d", type, type2, index, value)==4)
        {
        	if (type==0) COUND_d->set_1(type2, index, value);
        	else COUND_d->set_2(type2, index, value);
        	"/sys/user/energy"->count_all_prop(me);
        	main(me, sprintf("%d", type2));
        	return 1;
        }
        if (sscanf(arg, "%d %d %d", type, type2, index)==3)
        {
        	if (type==0)
                	send_user( me, "%c%c%d%s", '?', 1, 999999, sprintf("���뽫"+get_fam_word(index)+"�е�"+get_type_word(type2)+"�ӳ�ϵ����Ϊ���٣�\n"
                        	ESC "energy %d %d %d %%s\n", type, type2, index ) );        	
		else
                	send_user( me, "%c%c%d%s", '?', 1, 999999, sprintf("���뽫"+get_fam_word(index)+"�е�"+get_type_word(type2)+"����ϵ����Ϊ���٣�\n"
                        	ESC "energy %d %d %d %%s\n", type, type2, index ) );        	
		return 1;		                        
	}
	if (sscanf(arg, "%d %d", type2, index)==2)
	{
		cmd1 = sprintf( ESC "�ӳ�ϵ��\nenergy 0 %d %d\n", type2, index);
		cmd2 = sprintf( ESC "����ϵ��\nenergy 1 %d %d\n", type2, index);
		send_user( me, "%c%s", ':', "�����޸�"+get_fam_word(index)+"��"+get_type_word(type2)+"��ʽ���ĸ���ֵ��\n"
			+ cmd1 + cmd2+
                	ESC "�뿪\nCLOSE\n" );
                return 1;
	}

	type2 = to_int(arg);
	cmd1 = sprintf( ESC "������: %d/%d\nenergy %d 0\n", COUND_d->get_1(type2, 0), COUND_d->get_2(type2, 0), type2);
	cmd2 = sprintf( ESC "�һ�Դ: %d/%d\nenergy %d 1\n", COUND_d->get_1(type2, 1), COUND_d->get_2(type2, 1), type2);
	cmd3 = sprintf( ESC "��ɽ: %d/%d\nenergy %d 2\n", COUND_d->get_1(type2, 2), COUND_d->get_2(type2, 2), type2);
	cmd4 = sprintf( ESC "������: %d/%d\nenergy %d 3\n", COUND_d->get_1(type2, 3), COUND_d->get_2(type2, 3), type2);
	cmd5 = sprintf( ESC "����: %d/%d\nenergy %d 4\n", COUND_d->get_1(type2, 4), COUND_d->get_2(type2, 4), type2);
	cmd6 = sprintf( ESC "éɽ: %d/%d\nenergy %d 5\n", COUND_d->get_1(type2, 5), COUND_d->get_2(type2, 5), type2);
	cmd7 = sprintf( ESC "����ɽ: %d/%d\nenergy %d 6\n", COUND_d->get_1(type2, 6), COUND_d->get_2(type2, 6), type2);
	cmd8 = sprintf( ESC "������: %d/%d\nenergy %d 7\n", COUND_d->get_1(type2, 7), COUND_d->get_2(type2, 7), type2);
        send_user( me, "%c%s", ':', "������"+get_type_word(type2)+"�Ĺ�ʽ��\n"
                + cmd1 + cmd2 + cmd3 + cmd4 + cmd5 + cmd6 + cmd7 + cmd8 +                                
                ESC "�뿪\nCLOSE\n" );
        return 1;	
	

        return 1;
}
