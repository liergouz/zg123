
#include <ansi.h>
#include <equip.h>
#include <task.h>
#include <npc.h>
#include <time.h>

mapping level_message = ([
	50:	({ "����ɽһ�������������", "50", "54", }), // ��
	55:	({ "�೤�ǻ����������", "55", "59", }),
	60:	({ "�Գ��ǻ����������", "60", "65", }),
	65:	({ "�س��ǻ����������", "65", "69", }),
	70:	({ "��������������", "70", "75", }),
	75:	({ "��ȶ������������", "75", "86", }),
	80:	({ "���˿ӻ����������", "80", "88", }),
	85:	({ "������Ĺ�����������", "85", "93", }),
	90:	({ "��ħ������������", "90", "97", }),
	95:	({ "���ƶ�һ�������������", "95", "100", }),
	100:	({ "�����Ż����������", "100", "108", }),
	105:	({ "����������������", "105", "112", }),
	110:	({ "������", "110", "116", }),
	115:	({ "������", "110", "116", }),
	]);


// ���������ɶ�������
void SAVE_BINARY() { }

void do_welcome(object me, object who, string arg)
{
	int type = to_int(arg);
	string result, *name;
	int iTime, day, p, level, i, size;
	mixed *mxTime;
	object item;
	level = me->get_level();
	if (MAIN_D->get_host_type()==6012)
	{
		result = sprintf("%s:\n    Ŀǰ����������δ���š�\n", who->get_name());
		result += ESC"�뿪";
		send_user(me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	}
	if (level<50)
	{
		result = sprintf("%s:\n    �������ڵĵȼ�������������������������ĵȼ�����50��֮�����������Ұɡ�\n", who->get_name());
		result += ESC"�뿪";
		send_user(me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	}
	if (level>120) 
	{
		result = sprintf("%s:\n    �����ڵ�����̫���ˡ�\n", who->get_name());
		result += ESC"�뿪";
		send_user(me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	}	
	if (me->get_city_name()!=who->get_city_name())
	{
		send_user(me, "%c%c%w%s", ':', 3, who->get_char_picid(), sprintf("%s:\n    ���������������������֮˵�޴�̸��\n", who->get_name()));
		return;
	}	
	if (me->get_save_2("refine.status")==1)
	{
		result = sprintf("%s:\n    ����ô��������Ͽ�ȥ����ЩΣ�����������յ���ħ��ֵ�����ս�����������ȥ��\n", who->get_name());
		result += ESC"�뿪";
		send_user(me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	}
	iTime = time();
	mxTime = localtime(iTime);
	day = mxTime[TIME_YDAY];	
	if (me->get_save_2("refine.status")==2&&me->get_save_2("refine.day")==day)
	{
		result = sprintf("%s:\n    ��λ��ʿ�������ģ������������ǵļ�ʦ������������������������������㻹��Ϊ���������ճ�����Щ��ħ�Ļ������������ǵļ�ʦ�������µ�������֮����������һ���ɣ�\n", who->get_name());
		result += ESC"�뿪\n";
		send_user(me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;
	}
	if( sizeof_inventory(me, 1, MAX_CARRY) >= MAX_CARRY )
	{
		result = sprintf("%s:\n    �ҿ���ȫ����������˶��������ӣ�����û����Ȱ�������û�õĶ�������һ�°ɣ�\n", who->get_name());
		result += ESC"�뿪\n";
		send_user(me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		return;		
	}		
	switch(type)
	{
	case 1000:
		result = sprintf("%s:\n    �Դӳ�ƽ֮ս�����µ����������ֺ��У����������亦���м����ˣ�����������Ѱ����һλ��ʦΪ����������һЩ��������ֻҪ�������������Щ��ħ���ɱ�����Ϳ��԰���ЩΪ���˼����ħ������ս����������档�����Ը��ȥ���ҹ���������ħն���Ļ����ҿ��Ը���һ������������ȥɱ��450������ʵ���൱�����֣�Ȼ��Ϳ��԰���Щ������ս��������ˡ�\n", who->get_name());
		result += sprintf(ESC"����\ntalk %x# welcome.1001\n", getoid(who));
		result += ESC"�ܾ�\n";
		send_user(me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		break;
	case 1001:		
		item = new ("/item/01/0100");
		if (!item) return;
                p =item->move(me, -1);
		item->add_to_user(p);  	
		level = (level/5)*5;
		if (level>110) level = 110;
		name = level_message[level];
		result = sprintf("%s:\n    һ�������������ս�450����ħ����꣬�������ڵ�ʵ���������ȥ"HIR"%s��%s��%s��������"NOR"����꣬���ռ�����������Ժ�"HIR"�Ҽ����������"NOR"���������ͻ���ͬ�������ħ����걻����������Ҳ����Ϊ����������õ�����ľ�ˡ�\n", who->get_name(), name[0], name[1], name[2]);		
		result += ESC"�뿪\n";
		send_user(me, "%c%c%w%s", ':', 3, who->get_char_picid(), result );
		me->delete_save_2("refine");
		me->set_save_2("refine.status", 1);
		me->set_save_2("refine.level", me->get_level());
		me->set_save_2("refine.level1", to_int(name[1]));
		me->set_save_2("refine.level2", to_int(name[2]));
		send_user( me, "%c%c%c%w%s", 0x51, 1, 1, TID_REFINE, "��������" ); 
		send_user( me, "%c%c%c%w%w%s", 0x51, 1, 2, TID_REFINE, 1, "����������" ); 
		send_user( me, "%c%s", '!', "����������");
		break;	
	}
}

string send_task_intro(object me)
{
	int level, i, size, exp;
	string result, *name, result2;
	if (me->get_save_2("refine.status")!=1) return "";
	level = me->get_save_2("refine.level");
	exp = "/sys/npc/energy"->get_exp_bonus(level);
	exp = exp*450/2;
	level = (level/5)*5;
	if (level<50) return "";
	if (level>110) level = 110;
	name = level_message[level];	
	result = sprintf(BLK"����Ŀ�ģ�\n"BLK"    ��%s��%s�����ֵ����һ��450���ս���������\n"BLK"    �����ȡ����%d/450��\n"BLK"����������\n"BLK"    �Դӳ�ƽ֮ս�����µ����������ֺ��У����������亦���м����ˣ���������һ����ʦ������һ����������ֻҪ�������������Щ��ħ���ɱ�����Ϳ��԰���ЩΪ���˼����ħ������ս����������棬��������Щ��ħ�Ͳ�������Ϊ���˼��ˡ��ҵ�Ŀ�ģ���Ҫȥ%sɱ��%s��������һ��450����Ȼ��Ϳ��԰���Щ������ս��������ˡ��ٰ�����������������������������\n"BLK"������%d�㾭��\n",
	                        name[1], name[2], me->get_save_2("refine.count"), name[0], name[1], exp);	                
	return result;	                        
}

void task_giveup(object player )
{
	int time;
	object item;
	send_user( player, "%c%c%c%w%w%s", 0x51, 1, 2, TID_REFINE, 1, "" );
	send_user( player, "%c%c%c%w%s", 0x51, 1, 1, TID_REFINE, "" );
	player->delete_save_2("refine");
	// ɾ��������
	item = present("������", player, 1, MAX_CARRY*4);
	if (item)
	{
		item->remove_from_user();
	        destruct(item);	
	}	       
}