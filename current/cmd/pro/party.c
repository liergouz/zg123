#include <ansi.h>
#include <time.h>
// �����������
int main( object me, string arg )
{
	int i;
	string result,tmp;
	string *exp_str;
	int iTime;
	mixed *mixTime;
        if( !is_gm2(me) && !is_god(me) ) 
        {
                notify( "��û���㹻��Ȩ�ޡ�" );
		return 1;
        }
	if ( arg && sscanf(arg,"%d.%s",i,tmp) != 2 )
		i = to_int(arg);
	
	switch (i)
	{
	default:
		send_user(me, "%c%c%w%s", ':',3,0,
			"��ѡ��:\n"
			+ sprintf(ESC"��һҳ\nparty 6666\n")
//			+ sprintf(ESC"���˽�\nparty 1\n")
//			+ sprintf(ESC"����\nparty 4\n")
			+ sprintf(ESC"��ŵ�¼����\nparty 100\n")
			+ sprintf(ESC"�ʳ�����ս\nparty 7\n")
//			+ sprintf(ESC"����ս�������콱\nparty 11\n")
//			+ sprintf(ESC"����ϵͳ\nparty 20\n")
//			+ sprintf(ESC"321����������˫������ʱ��\nparty 23\n")
//			+ sprintf(ESC"���ϴ򱦻����\nparty 33\n")
//			+ sprintf(ESC"�������ĺ�������\nparty 30\n")
//			+ sprintf(ESC"��һ�\nparty 39\n")
			+ sprintf(ESC"��������ս\nparty 43\n")
//			+ sprintf(ESC"��ɫ������\nparty 54\n")
//			+ sprintf(ESC"����ڻ����\nparty 50\n")
//			+ sprintf(ESC"�Ϸ�����\nparty 200\n")
			+ sprintf(ESC"�ڱ��ܶ�Ա\nparty 110\n")
			+ sprintf(ESC"�����װ\nparty 120\n")
			+ sprintf(ESC"�ٱ��������Ѳ�\nparty 1220\n")
			+ sprintf(ESC"��ٻ���\nparty 130\n")
//			+ sprintf(ESC"����͵Ϯս����(����)\nparty 125\n")
//			+ sprintf(ESC"�ƽ����ӳ�����(����)\nparty 127\n")
//			+ sprintf(ESC"��Ϧ�����(����)\nparty 135\n")
			+ sprintf(ESC"��Ĺ̽��\nparty 5000\n")
//			+ sprintf(ESC"����ڻ����(����)\nparty 138\n")
			+ sprintf(ESC"����ڻ����\nparty 151\n")
			+ sprintf(ESC"�����ڻ����\nparty 157\n")
			+ sprintf(ESC"�Ϸ�����\nparty 200\n")
			+ ESC"�뿪"
		);
		break;
	case 6666:
		send_user(me, "%c%c%w%s", ':',3,0,
			"��ѡ��:\n"
			+ sprintf(ESC"��һҳ\nparty\n")
			+ sprintf(ESC"Ѱ��dodolook\nparty 12\n")
			+ sprintf(ESC"Ե�ֶԶ���\nparty 26\n")
			+ sprintf(ESC"����������\nparty 16\n")
			+ sprintf(ESC"��˫����ս\nparty 7000\n")
			+ ESC"�뿪"
		);		
		break;
	case 1:
		send_user(me, "%c%c%w%s", ':',3,0,
			"��ѡ�����˽ڻ�Ĳ���:\n"
			+ sprintf(ESC"����\nparty 2\n")
			+ sprintf(ESC"��Ԥ��ʱ�俪��\nparty 214\n")
			+ sprintf(ESC"�ر�\nparty 3\n")
			+ ESC"�뿪"
		);
		break;
	case 2:
		"sys/user/marry"->set_valentine(1,0);
		"sys/party/valentine"->set_valentine(1,0);
		send_user(me,"%c%s",'!',"���˽ڻ������!");
		break;	
	case 214:
		"sys/user/marry"->set_valentine(0,0);
		"sys/party/valentine"->set_valentine(0,0);
		"sys/party/valentine"->destruct_chocolate();
		"sys/party/valentine"->check_time();
		send_user(me,"%c%s",'!',"���˽ڻ��Ԥ��ʱ�俪��!");
		break;	
	case 3:
		"sys/user/marry"->set_valentine(0,1);
		"sys/party/valentine"->set_valentine(0,1);
		"sys/party/valentine"->destruct_chocolate();
		send_user(me,"%c%s",'!',"���˽ڻ�ر���!");
		break;	
	case 4:
		send_user(me, "%c%c%w%s", ':',3,0,
			"��ѡ�񴺽ڻ�Ĳ���:\n"
			+ sprintf(ESC"����\nparty 5\n")
			+ sprintf(ESC"��Ԥ��ʱ�俪��\nparty 216\n")
			+ sprintf(ESC"�ر�\nparty 6\n")
			+ ESC"�뿪"
		);
		break;
	case 5:
		"npc/00/0008"->set_newyear(1,0);
		"sys/party/chunjie"->set_newyear(1,0);
		"sys/party/chunjie"->generate_fuwawa();
		send_user(me,"%c%s",'!',"���ڻ������!");
		break;
	case 7:
		result = "��ѡ��ʳ�����ս�Ĳ���:\n";
		if ("/sys/sys/count"->get_war_flag1())
			result += ESC"�رջʳ�����ս\nparty 8\n";
		else
			result += ESC"�����ʳ�����ս\nparty 8\n";
		result += ESC"���������ʳ�����ս\nparty 9\n";
		result += ESC"�뿪";
		send_user(me, "%c%c%w%s", ':',3,0, result);
		break;		
	case 8:
		if ("/sys/sys/count"->get_war_flag1())
		{
			"/sys/sys/count"->set_war_flag1(0);
			send_user(me,"%c%s",'!',"�ʳ�����ս�ر�!");
		}
		else
		{
			"/sys/sys/count"->set_war_flag1(1);
			send_user(me,"%c%s",'!',"�ʳ�����ս����!");
		}		
		break;
	case 9:
		"/sys/party/defence"->start_defence();
		break;		
	case 216:
		"npc/00/0008"->set_newyear(0,0);
		"sys/party/chunjie"->set_newyear(0,0);
		"sys/party/chunjie"->destroy_baozhu();
		"sys/party/chunjie"->destroy_nianshou();
		"sys/party/chunjie"->destroy_fuwawa();
		"sys/party/chunjie"->check_time();		
		send_user(me,"%c%s",'!',"���ڻ��Ԥ��ʱ�俪��!");
		break;
	case 6:
		"npc/00/0008"->set_newyear(0,1);
		"sys/party/chunjie"->set_newyear(0,1);
		"sys/party/chunjie"->destroy_baozhu();
		"sys/party/chunjie"->destroy_nianshou();
		"sys/party/chunjie"->destroy_fuwawa();
		send_user(me,"%c%s",'!',"���ڻ�ر���!");
		break;
	case 11:
		"npc/party/0014"->read_renwang();
		send_user(me,"%c%s",'!',"ս�������콱����!");
		break;
	case 12:
		result = "��ѡ��Ѱ��dodolook��Ĳ���:\n";
		result += ESC"����\nparty 13\n";
		result += ESC"�ر�\nparty 14\n";
		result += ESC"�뿪";
		send_user(me, "%c%c%w%s", ':',3,0, result);
		break;	
	case 13:
		send_user( me, "%c%c%d%s", '?', 16, 60, "�������Ŀ�ʼʱ��ͽ���ʱ�䣨���磺20070315-20070430 ����\n"ESC"party 15.%s\n");		
		break;
	case 14:
		"npc/party/0022"->set_close(me);
		break;
	case 15:
		"npc/party/0022"->set_open(me,tmp);
		break;		
	case 16:
		send_user(me, "%c%c%w%s", ':',3,0,
			"��ѡ�������������Ĳ���:\n"
			+ sprintf(ESC"����\nparty 17\n")
			+ sprintf(ESC"�ر�\nparty 18\n")
			+ ESC"�뿪"
		);
		break;
	case 17:
		"npc/party/0023"->set_open();
		send_user( me, "%c%s", '!',"����������������"); 
		break;	
	case 18:
		"npc/party/0023"->set_close();
		send_user( me, "%c%s", '!',"�����������رգ�"); 
		break;
	case 20:
		result = "��ѡ����ϵͳ�Ĳ���:\n";
		if ("/sys/item/box"->get_all_stuff())
			result += ESC"�رձ���ϵͳ\nparty 21\n";
		else
			result += ESC"��������ϵͳ\nparty 22\n";
		result += ESC"�뿪";
		send_user(me, "%c%c%w%s", ':',3,0, result);
		break;		
	case 21:
		"/sys/item/box"->del_stuff();
		send_user(me,"%c%s",'!',"����ϵͳ�ر�!");
		break;		
	case 22:
		"/sys/item/box"->reset_stuff();
		send_user(me,"%c%s",'!',"����ϵͳ����!");
		break;				
	case 23:
		send_user(me, "%c%c%w%s", ':',3,0,
			"321����������˫������ʱ��Ĳ���:\n"
			+ sprintf(ESC"����\nparty 24\n")
			+ sprintf(ESC"�ر�\nparty 25\n")
			+ ESC"�뿪"
			);
		break;
	case 24:
		"npc/party/0026"->set_open(me);
		break;	
	case 25:
		"npc/party/0026"->set_close(me);
		break;	
	case 26:
		result = "��ѡ��Ե�ֶԶ�����Ĳ���:\n";
		result += ESC"����\nparty 27\n";
		result += ESC"�ر�\nparty 28\n";
		result += ESC"�뿪";
		send_user(me, "%c%c%w%s", ':',3,0, result);
		break;	
	case 27:
		send_user( me, "%c%c%d%s", '?', 16, 60, "������Ե�ֶԶ�����Ŀ�ʼʱ�䣨���磺20070416 ����\n"ESC"party 29.%s\n");		
		break;
	case 28:
		"npc/party/dodolook"->set_close(me);
		break;
	case 29:
		"npc/party/dodolook"->set_open(me,tmp);
		break;	
	case 30:
		send_user(me, "%c%c%w%s", ':',3,0,
			"�������ĺ������Ĳ���:\n"
			+ sprintf(ESC"����\nparty 31\n")
			+ sprintf(ESC"�ر�\nparty 32\n")
			+ ESC"�뿪"
		);
		break;
	case 31:
		"npc/org/qgl_amass"->set_open2();
		send_user( me, "%c%s", '!',"�������ĺ�������������"); 
		break;	
	case 32:
		"npc/org/qgl_amass"->set_close2();
		send_user( me, "%c%s", '!',"�������ĺ��������رգ�"); 
		break;
	case 33:
		send_user(me, "%c%c%w%s", ':',3,0,
			"���ϴ򱦻����:\n"
			+ sprintf(ESC"�׼��״̬\nparty 36\n")
			+ sprintf(ESC"ֱ�ӿ���(������,��Ҫ����ʽ�ʱʹ��!)\nparty 34\n")
			+ sprintf(ESC"���ÿ���/����ʱ��\nparty 37\n")
			+ sprintf(ESC"ֱ�ӹر�(������,��Ҫ����ʽ�ʱʹ��!)\nparty 35\n")
			+ ESC"�뿪"
		);
		break;
	case 34:
		"npc/org/qgl_amass"->set_open();
		"npc/party/dodolook2"->set_open();
		"sys/npc/npc"->set_open();
		send_user( me, "%c%s", '!',"���ϴ򱦻�ѿ�����"); 
		break;	
	case 35:
		"npc/org/qgl_amass"->set_close();
		"npc/party/dodolook2"->set_close();
		"sys/npc/npc"->set_close();
		send_user( me, "%c%s", '!',"���ϴ򱦻�ѹرգ�"); 
		break;
	case 36:
		"npc/org/qgl_amass"->set_prepare();
		"npc/party/dodolook2"->set_prepare();
		"sys/npc/npc"->set_prepare();
		send_user( me, "%c%s", '!',"���ϴ򱦻����׼���У�"); 
		break;
	case 37:
		send_user( me, "%c%c%d%s", '?', 16, 60, "���������ϴ򱦻�Ŀ�ʼʱ��ͽ���ʱ�䣨���磺20070517-20070721 ����\n"ESC"party 38.%s\n");
		break;
	case 38:
		"npc/party/dodolook2"->set_open_time(me,tmp);
		"npc/org/qgl_amass"->set_open_time(me,tmp);
		"sys/npc/npc"->set_open_time(me,tmp);
		break;
	case 39:
		result = "��ѡ����һ��Ĳ���:\n";
		result += ESC"����\nparty 40\n";
		result += ESC"�ر�\nparty 41\n";
		result += ESC"�뿪";
		send_user(me, "%c%c%w%s", ':',3,0, result);
		break;	
	case 40:
		send_user( me, "%c%c%d%s", '?', 16, 60, "��������һ��Ŀ�ʼʱ��ͽ���ʱ�䣨���磺20070501-20070508 ����\n"ESC"party 42.%s\n");		
		break;
	case 41:
		"npc/party/0032"->set_close(me);
		break;
	case 42:
		"npc/party/0032"->set_open(me,tmp);
		break;	
	case 43:
		result = "��ѡ����������ս�Ĳ���:\n";
		result += ESC"����\nparty 44\n";
		result += ESC"�ر�\nparty 45\n";
		result += ESC"�뿪";
		send_user(me, "%c%c%w%s", ':',3,0, result);
		break;	
	case 44:
		send_user( me, "%c%c%d%s", '?', 16, 60, "��������������ս�Ŀ�ʼʱ�䡢����ʱ��Ͱ佱ʱ�䣨���磺200705182000-200705182100-200705182130 ����\n"ESC"party 46.%s\n");		
		break;
	case 45:
		TASK_ESCORT_D->set_close(me);
		break;
	case 46:
		TASK_ESCORT_D->set_open(me,tmp);
		break;	
	case 47:
		send_user(me, "%c%c%w%s", ':',3,0,
			"��ɫ��(����)����:\n"
			+ sprintf(ESC"��ʼ����\nparty 48\n")
			+ sprintf(ESC"�������ԡ�ע�⣺����е���Ӧ���ڴ�״̬\nparty 49\n")
			+ ESC"�뿪"
		);
		break;
	case 48:
		"sys/npc/npc"->test_start();
		send_user( me, "%c%s", '!',"��ʼ��ɫ����ԣ�ע��������һ��Ҫ������"); 
		break;	
	case 49:
		"sys/npc/npc"->test_finish();
		send_user( me, "%c%s", '!',"������ɫ����ԣ�"); 
		break;
	case 50:
		result = "��ѡ�����ڻ�Ĳ���:\n";
		result += ESC"����\nparty 51\n";
		result += ESC"�ر�\nparty 52\n";
		result += ESC"�뿪";
		send_user(me, "%c%c%w%s", ':',3,0, result);
		break;	
	case 51:
		send_user( me, "%c%c%d%s", '?', 16, 60, "���������ڻ�Ŀ�ʼʱ��ͽ���ʱ�䣨���磺200706190900-200706192300 ����\n"ESC"party 53.%s\n");
		break;
	case 52:
		"sys/party/duanwujie"->set_close(me);
		"sys/party/duanwujie"->destruct_dongtingzhouzi();
		"sys/party/duanwujie"->destroy_zhongzi();
		break;
	case 53:
		"sys/party/duanwujie"->set_open(me,tmp);
		break;	
	case 54:
		send_user(me, "%c%c%w%s", ':',3,0,
			"��ɫ������:\n"
			+ sprintf(ESC"��ɫ��(����)����\nparty 47\n")
			+ sprintf(ESC"������ɫ������ʱ��\nparty 55\n")
			+ sprintf(ESC"ȡ��������ɫ������ʱ��\nparty 57\n")
			+ ESC"�뿪"
		);
		break;
	case 55:
		send_user( me, "%c%c%d%s", '?', 16, 60, "��������ɫ������ʱ��(���磺200707190900)��\n"ESC"party 56.%s\n");
		break;
	case 56:
		"sys/npc/npc"->set_ball_close_time(me,tmp);
		break;	
	case 57:
		"sys/npc/npc"->set_ball_cancel(me);
		break;

	case 100:
		result = "��ѡ���ŵĿ���:\n";
		if ("/sys/sys/count"->get_can_gm3())
			result += ESC"��ֹ��ŵ�¼\nparty 101\n";
		else
			result += ESC"�����ŵ�¼\nparty 102\n";
		result += ESC"�뿪";
		send_user(me, "%c%c%w%s", ':',3,0, result);
		break;		
	case 101:
		"/sys/sys/count"->set_can_gm3(0);
		send_user(me,"%c%s",'!',"���ڽ�ֹ��ŵ�¼!");
		break;
	case 102:
		"/sys/sys/count"->set_can_gm3(1);
		send_user(me,"%c%s",'!',"���������ŵ�¼!");
		break;	
	case 200:
		result = "��ѡ��Ϸ������Ŀ���:\n";
		result += ESC"�رպϷ�����\nparty 201\n";
		result += ESC"���źϷ�����\nparty 202\n";
		result += ESC"�뿪";
		send_user(me, "%c%c%w%s", ':',3,0, result);
		break;	
	case 201:	
		"/sys/sys/count"->set_hefu_time(0);
		send_user(me,"%c%s",'!',"���ڹرպϷ�����!");
		break;
	case 202:		
		send_user( me, "%c%c%d%s", '?', 16, 60, "������Ϸ��Ĵ������Ϸ��Ľ���ʱ��(���磺2 200707190900)��\n"ESC"party 203.%s\n");
		break;			
	case 203:
		"sys/sys/count"->set_hefu_time2(me,tmp);
		break;	
	case 110://�ڱ��ܶ�Ա
		result = "��ѡ���ڱ��ܶ�Ա������\n";
		result += ESC"����\nparty 111\n";
		result += ESC"�ر�\nparty 112\n";
		result += ESC"�뿪";
		send_user(me,"%c%c%w%s",':',3,0,result);
		break;
	case 111:
		send_user( me, "%c%c%d%s", '?', 16, 60, "�������ڱ��ܶ�Ա�Ŀ�ʼʱ��ͽ���ʱ�䣨���磺200706190900-200706192300 ����\n"ESC"party 113.%s\n");
		break;
	case 112:
		"sys/party/treasure"->set_close(me);
		break;
	case 113:
		"sys/party/treasure"->set_open(me,tmp);
		break;	
	case 120:
		result = "��ѡ�񡰾����װ���Ĳ���:\n";
		result+= ESC"�����\nparty 121\n";
		result+= ESC"ֹͣ�\nparty 122\n";
		result+= ESC"���ûʱ��\nparty 123\n";
		send_user(me,"%c%c%w%s",':',3,0,result);
		break;
	case 121:
		"sys/party/burst_equips"->turn_on_activity();
		break;
	case 122:
		"sys/party/burst_equips"->turn_off_activity();
		break;
	case 123:
		result = "��������ֹʱ�䣬����\"51700-51800\" ��ʾÿ����� 17��-18��Ϊ���ʼʱ�� \n"ESC"party 124.%s\n";
		send_user(me, "%c%c%d%s", '?', 16, 60, result);
		break;
	case 124:
		exp_str = explode(tmp,"-");
		if(sizeof(exp_str) != 2) {
			send_user(me,"%c%s",'!',"����ĸ�ʽ��");
		} else {
			"sys/party/burst_equips"->set_active_time(to_int(exp_str[0]),to_int(exp_str[1]));
		}		
		break;
	case 1220:
		result = "��ѡ�񡰽ٱ��������Ѳ����Ĳ���:\n";
		result+= ESC"�����\nparty 1221\n";
		result+= ESC"ֹͣ�\nparty 1222\n";
		result+= ESC"���ûʱ��\nparty 1223\n";
		result+= ESC"�鿴�״̬\nparty 1224\n";
		send_user(me,"%c%c%w%s",':',3,0,result);		
		break;
	case 1221:
		"sys/party/feizei"->turn_on_activity();
		send_user(me,"%c%s",';',"�ɹ��������");
		break;
	case 1222:
		"sys/party/feizei"->turn_off_activity();
		send_user(me,"%c%s",';',"�ɹ��رջ!");
		break;
	case 1223:
		result = "��������ֹʱ�䣬����\"1,2,3,4;9,23;2\" ��ʾÿ��һ������������ 9�㵽23�㿪ʼ���ÿ��2��ʱˢ�� \n"ESC"party 1225.%s\n";
		send_user(me, "%c%c%d%s", '?', 16, 60, result);
		break;
	case 1224:
		tell_user(me,"sys/party/feizei"->get_active_time());
		break;
	case 1225:
		if("sys/party/feizei"->set_active_time(tmp)) {
			send_user(me,"%c%s",';',sprintf("�ɹ��޸Ļʱ��,�������\n%s","sys/party/feizei"->get_active_time()));
		} else {
			send_user(me,"%c%s",';',"��������ַ���ʽ������Ҫ��û���޸ĳɹ�");
		}
		break;
	case 125:
		send_user(me, "%c%c%w%s", ':',3,0,
			"����͵Ϯս�����:\n"
			+ sprintf(ESC"��ʼ����\nparty 126\n")
			+ ESC"�뿪"
		);
		break;
	case 126:
		"sys/party/sect_surprise"->generate_scum();
		break;		
	case 127:
		send_user(me, "%c%c%w%s", ':',3,0,
			"�ƽ����ӳ������:\n"
			+ sprintf(ESC"��ʼ����\nparty 128\n")
			+ ESC"�뿪"
		);
		break;
	case 128:
		"sys/party/gold_warrior"->check_time2();
		break;	
	case 130:
		result = "��ѡ����ٻ������Ĳ���:\n";
		result+= ESC"�����\nparty 131\n";
		result+= ESC"�رջ\nparty 132\n";
		result+= ESC"���ûʱ��\nparty 133\n";
		send_user(me,"%c%c%w%s",':',3,0,result);
		break;
	case 131:
		"sys/party/guess_true_tiger"->turn_on_activity();
		break;
	case 132:
		"sys/party/guess_true_tiger"->turn_off_activity();
		break;
	case 133:
		result = "��������ֹʱ�䣬����\"50900-60000\" ��ʾÿ����� 9��-24��Ϊ���ʼʱ�� \n"ESC"party 134.%s\n";
		send_user(me, "%c%c%d%s", '?', 16, 60, result);
		break;
	case 134:
		exp_str = explode(tmp,"-");
		if(sizeof(exp_str) != 2) {
			send_user(me,"%c%s",'!',"����ĸ�ʽ��");
		} else {
			"sys/party/guess_true_tiger"->set_active_time(to_int(exp_str[0]),to_int(exp_str[1]));
		}		
		break;		


	//====================wg=================
	case 135:
		send_user(me, "%c%c%w%s", ':',3,0,
			"��Ϧ�����:\n"
			+ sprintf(ESC"��ʼ����\nparty 136\n")
			+ sprintf(ESC"��������\nparty 137\n")
			+ ESC"�뿪"
		);
		break;
	case 136:
		"sys/party/qixi"->check_time2();
		break;
	case 137:
		"sys/party/qixi"->check_time3();
		break;
	case 138:
		send_user(me, "%c%c%w%s", ':',3,0,
			"����ڻ����:\n"
			+ sprintf(ESC"��ʼ����\nparty 139\n")
			+ sprintf(ESC"��ʼ��ȡץ�ý���\nparty 144\n")
			+ sprintf(ESC"��������\nparty 143\n")
			+ ESC"�뿪");
		break;
	case 139:
		set_party_time(2007,9,24,8,0,0);
		"sys/party/moon1"->check_time();
		break;
	case 143:
		set_party_time(2007,10,3,22,0,0);
		"sys/party/moon1"->check_time();
		break;
	case 144:
		set_party_time(2007,9,26,22,0,0);
		"sys/party/moon1"->check_time();
		break;
	case 145:
		send_user(me, "%c%c%w%s", ':',3,0,
			"����ڻ֮�������ϲ����Ĳ���:\n"
			+ sprintf(ESC"��������ڻ֮�������ϲ���\nparty 146\n")
			+ sprintf(ESC"������ǰʱ��������ڻ֮�������ϲ�������ʼʱ��\nparty 147\n")
			+ sprintf(ESC"������ڻ֮�������ϲ���״̬\nparty 148\n")
			+ sprintf(ESC"��ʱ�仹ԭΪ��׼��ϵͳʱ��\nparty 149\n")
			+ sprintf(ESC"��ֹ����ڻ֮�������ϲ���\nparty 150\n")
			+ ESC"�뿪");
		break;
	case 146:
		"sys/party/national"->set_open();
		send_user(me,"%c%s",';',"�ɹ���������ڻ֮�������ϲ�����");
		break;
	case 147:
		set_party_time(2007,10,1,8,0,0);
		"sys/party/national"->check_time();
        	tell_user(me,"��ǰʱ�����Ϊ��%s",short_time(get_party_time()));
		break;
	case 148:
        	tell_user(me,"��ǰ�ʱ���ǣ�%s",short_time(get_party_time()));
		if ("sys/party/national"->get_status()==0) tell_user(me,"����ڻ֮�������ϲ������ڹر�״̬");
		else tell_user(me,"����ڻ֮�������ϲ������ڿ���״̬");
		break;
	case 149:
		iTime = time();
		mixTime=localtime(iTime);
		set_party_time(mixTime[TIME_YEAR],mixTime[TIME_MON]+1,mixTime[TIME_MDAY],mixTime[TIME_HOUR],mixTime[TIME_MIN],mixTime[TIME_SEC]);
		"sys/party/national"->destruct_xigua_uncle();
		"sys/party/national"->destruct_xigua();
		"sys/party/national"->destruct_bad_npc();
		"sys/party/national"->check_time();
        	tell_user(me,"��ǰʱ�仹ԭ��׼ȷ��ϵͳʱ�䣺%s",short_time(time()));
		break;
	case 150:
		"sys/party/national"->set_close();
		send_user(me,"%c%s",';',"�ɹ���ֹ����ڻ֮�������ϲ�����");
		break;

	case 151:
		send_user(me, "%c%c%w%s", ':',3,0,
			"����ڻ����:\n"
			+ sprintf(ESC"���ϲ����Ļ\nparty 145\n")
			+ sprintf(ESC"��������\nparty 152\n")
			+ ESC"�뿪");
		break;
	case 152://��������
		result = "��ѡ�����ڻ֮�����������������\n";
		result += ESC"����\nparty 153\n";
		result += ESC"�ر�\nparty 154\n";
		result += ESC"���״̬\nparty 156\n";
		result += ESC"�뿪";
		send_user(me,"%c%c%w%s",':',3,0,result);
		break;
	case 153:
		send_user( me, "%c%c%d%s", '?', 16, 60, "���������ڻ֮������������Ŀ�ʼʱ��ͽ���ʱ�䣨���磺200706190900-200706192300 ����\n"ESC"party 155.%s\n");
		break;
	case 154:
		"npc/party/exchange_angel"->set_close(me);
		break;
	case 155:
		"npc/party/exchange_angel"->set_open(me,tmp);
		break;
	case 156:
		if ("npc/party/exchange_angel"->is_open()) tell_user(me,"����ڻ֮�������������ڿ���״̬");
		else tell_user(me,"����ڻ֮�������������ڹر�״̬");
		break;

	case 157:
		send_user(me, "%c%c%w%s", ':',3,0,
			"�����ڻ����:\n"
			+ sprintf(ESC"�����\nparty 158\n")
			+ sprintf(ESC"������ǰʱ���������ڻ����ʼʱ��\nparty 159\n")
			+ sprintf(ESC"���״̬\nparty 160\n")
			+ sprintf(ESC"��ʱ�仹ԭΪ��׼��ϵͳʱ��\nparty 161\n")
			+ sprintf(ESC"��ֹ�\nparty 162\n")
			+ ESC"�뿪");
		break;
	case 158:
		"sys/party/chongyang"->set_open();
		send_user(me,"%c%s",';',"�ɹ��������");
		break;
	case 159:
		set_party_time(2007,10,19,9,50,0);
		"sys/party/chongyang"->check_time();
        	tell_user(me,"��ǰʱ�����Ϊ��%s",short_time(get_party_time()));
		break;
	case 160:
        	tell_user(me,"��ǰ�ʱ���ǣ�%s",short_time(get_party_time()));
		if ("sys/party/chongyang"->get_status()==0) tell_user(me,"�����ڻ���ڹر�״̬");
		else tell_user(me,"�����ڻ���ڿ���״̬");
		break;
	case 161:
		iTime = time();
		mixTime=localtime(iTime);
		set_party_time(mixTime[TIME_YEAR],mixTime[TIME_MON]+1,mixTime[TIME_MDAY],mixTime[TIME_HOUR],mixTime[TIME_MIN],mixTime[TIME_SEC]);
		"sys/party/chongyang"->destruct_party_npc();
		"sys/party/chongyang"->destruct_party_item();

		"sys/party/chongyang"->check_time();
        	tell_user(me,"��ǰʱ�仹ԭ��׼ȷ��ϵͳʱ�䣺%s",short_time(time()));
		break;
	case 162:
		"sys/party/chongyang"->set_close();
		send_user(me,"%c%s",';',"�ɹ���ֹ���");
		break;

	//====================end=================



	/************************************XXY************************************/
	case 5000: 
		send_user(me,"%c%c%w%s",':',3,0,"��Ĺ̽�ղ���:\n"
		           +sprintf(ESC HIY"��ʼ����\nparty 5001\n")
		           +sprintf(ESC HIY"�رղ���\nparty 5002\n")
		           +sprintf(ESC HIY"���״̬\nparty 5005\n")
		           +sprintf(ESC HIY"��ʼ�(��������)\nparty 5003\n")
		           +sprintf(ESC HIY"�رջ(���ùر�)\nparty 5004\n")
		           +ESC"�뿪");
		break;
	case 5001:
		"sys/party/gumu_check_time"->set_gumu_party_open(1,1);
		break;
	case 5002:
		"sys/party/gumu_check_time"->set_gumu_party_open(0,1);
		break;
	case 5003:
		"sys/party/gumu_check_time"->set_gumu_party_open(1,0);
		break;
	case 5004:
		"sys/party/gumu_check_time"->set_gumu_party_open(0,0);
		break;
	case 5005:
		tell_user(me,sprintf(HIY"��ǰ��Ϸʱ��Ϊ: %s",short_time(get_party_time())));
		tell_user(me,sprintf(HIY"%s","sys/party/gumu_check_time"->get_party_statue()));
		break;
	/************************************XXY************************************/
	//====================lyt================
	case 7000:
		send_user(me, "%c%c%w%s", ':',3,0,
			"��˫����ս����:\n"
			+ sprintf(ESC"�޸���Ϸ��ϵͳʱ��(������)\nparty 7001\n")
			+ sprintf(ESC"�����ʱ�俪��\nparty 7003\n")
			+ sprintf(ESC"ǿ�йرջ\nparty 7004\n")
			+ sprintf(ESC"�״̬\nparty 7005\n")
			+ ESC"�뿪");
		break;
	case 7001:
		send_user( me, "%c%c%d%s", '?', 16, 60, "�������ĵ�ǰʱ�䣨��ʽ�磺2007-9-18 19:29:30 ����\n"ESC"party 7002.%s\n");		
		break;
	case 7002:
		WUSHUANG->set_wushuang_time(me,tmp);
		break;
	case 7003:
		WUSHUANG->set_flag(1);
		break;
	case 7004:
		WUSHUANG->set_flag(0);
		break;
	case 7005:
		WUSHUANG->get_status(me);
		break;
	case 7999:
		break;
	//====================end=================	
	}
        return 1;
}



