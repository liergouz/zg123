
#include <npc.h>
#include <ansi.h>
#include <task.h>
#include <time.h>

#define TREASURE        "/item/std/8000"

#define LT_SEC          0
#define LT_MIN          1
#define LT_HOUR         2
#define LT_MDAY         3
#define LT_MON          4
#define LT_YEAR         5
#define LT_WDAY         6
#define LT_YDAY         7
#define LT_GMTOFF       8
#define LT_ZONE         9

inherit OFFICER;

int iStart2,iFinish2,close_val,open_val;
void do_look( object who );
void do_welcome( string arg );
int is_holiday();

// ��������ȡ��������
int get_char_picid() { return 6008; }

// ���������촦��
void create()
{
        set_name( "����үү" );

        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ]));
//	set("mpLegend",([0:({32*48+1}),10:({11,}),30:({9,13})]));
//	set("mpLegend2",([0:({24,2}),]));
        setup();
	set("mpLegend",([0:({32}),]));	//����Ҫ���������

        iStart2 = mktime(2007,2,16,0,0,0);
        iFinish2 = mktime(2007,2,21,0,0,0);


}

// �������Ի�����
void do_look( object who )
{
	int x;
	x = (time() - 4 * 24*3600+8*3600) / (7*24*3600);
	if (who->get_save_2("double_time.week")!=x)
	{
		who->set_save_2("double_time.week", x);
		who->set_save_2("double_time.time", 0);		//˫
		who->set_save_2("double_time.time1", 0);	//ս����
		who->set_save_2("double_time.time2", 0);	//ս���Ž�
		who->set_save_2("double_time.time3", 0);	//���⻻ȡ��3Сʱ˫��ʱ��
		who->set_save_2("double_time.freeze", 0);	//�����˫��ʱ��
	}
        do_welcome("99");
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag, date , status, p, z, x, y, i;
        object who, obj, item, item2;
        string cmd1, cmd2, cmd3, cmd4, cmd5, cmd6, cmd7, cmd8, result;
        mixed mxTime;
	int iVipTime;
	
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        p = 0;
        z = get_z(me);
	x = (time() - 4 * 24*3600+8*3600) / (7*24*3600);
	if (who->get_save_2("double_time.week")!=x)
	{
		who->set_save_2("double_time.week", x);
		who->set_save_2("double_time.time", 0);		//˫
		who->set_save_2("double_time.time1", 0);	//ս����
		who->set_save_2("double_time.time2", 0);	//ս���Ž�
		who->set_save_2("double_time.time3", 0);	//������˫
		who->set_save_2("double_time.freeze", 0);	//�����˫��ʱ��
	}
        switch(flag)
        {
        case 1:
        	if (who->get_legend(TASK_NEWBIE_00, 1) && !who->get_legend(TASK_NEWBIE_00, 2))
        	{
	                cmd1 = sprintf("talk %x# welcome.2\n", getoid(me));
	                result =  get_name() + "��\n    �Ǻǡ�����һ����һ������ʿ����������ĸо��ܿ��ġ����ð�ղŸտ�ʼ���㲻���������ִ���˽�һ�¸������ܣ��������ʲô�����׵ĵط��������ȥ��ָ��������һ�¡�\n"
	                		ESC "�������\n" + cmd1 +
	                		ESC "�ر�\nCLOSE\n";
	                send_user( who, "%c%c%w%s", ':', 3, 6008, result );
		}
                break;
        case 2:
                if (who->get_legend(TASK_NEWBIE_00, 1) && !who->get_legend(TASK_NEWBIE_00, 2))
                {
			if (who->get_save_2("double_time.freeze")>0)
			{
			        send_user( who, "%c%c%w%s", ':', 3, 6008,
			        	sprintf("%s��\n     ���"HIR"˫������ʱ���Ѿ�����"NOR"����������״̬������ȡ�����˫������ɡ�\n"
			                ESC "�ر�\nCLOSE\n", me->get_name() ) );
				return;
			}                	
                	// ��ȥ�ٺ����ӵ��ż�
			TASK_LEGEND_D->task_finish(who);
                        who->set_legend(TASK_NEWBIE_00, 2);
                        who->add_exp(20);
                        who->add_cash(500);
                        who->add_potential(20);
                        "/quest/help"->send_help_tips(who, 2);

	        	mxTime = localtime(time());
	        	if ( who->get_save("dbtime_s") == mxTime[TIME_YDAY] )
	        	{
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),me->get_name()+"��\n    ���Ѿ������͸����˫��������ѽ��");
	        		return ;
	        	}
	        	i = gone_time( who->get_login_time() );

	        	who->set_save("dbtime_s",mxTime[TIME_YDAY]);
	        	if ( i+ who->get_game_time()<who->get_double_time())
	        		who->set_double_time(who->get_double_time()+1800);
			else
				who->set_double_time(i+ who->get_game_time()+1800);
			who->delete("tasklist");
			send_user( who, "%c%c%c%w%s", 0x51, 1, 1,0001,"��Ϸ����" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "˫��ʱ��" );
			"/sys/task/task"->send_task_intro(who, 1, 1, 1);
			"/quest/help"->send_help_tips(who, 3);
                        result = "���õ�������үү�Ľ��� 20 �㾭�顢20 ��Ǳ�ܡ�500 ��Ͱ�Сʱ˫������";
                        send_user( who, "%c%s", ';', result);
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),me->get_name()+"��\n    ��������30���ӵ�˫������ʱ�䣬�úð��հɡ�");

			send_user( who, "%c%c%c%w%c", 0x51, 2, 1,TID_NEWBIE_00,0 );
			send_user( who, "%c%c%c%w%w%c", 0x51, 2, 2,TID_NEWBIE_00,1,0 );
                        "/sys/sys/count"->add_task("����ʹ��", 1);
	        	if (who->get_legend(TASK_48, 1))  return;
	                cmd1 = sprintf("talk %x# welcome.21\n", getoid(me));
	                result =  get_name() + "��\n    ��������ִ��⣬�ֲ���һЩ����ֵĶ�����ǲ�����ͨ��С����С�á�������һ�������ƣ����ǻṥ���ˣ�������Щ����������һֱ�������������飬������ܹ�Э���ҳ�����Щ��ֵ�С����ͺ��ˣ�\n    �������ϰ����������һЩ�����ģ���ɱ���ȥ�����ɡ�\n"

	                		ESC "��ȡ����\n" + cmd1 +
	                		ESC "�ر�\nCLOSE\n";
	                send_user( who, "%c%c%w%s", ':', 3, 6008, result );

                }
                else
                	send_user( who, "%c%s", '!', "������û����������");
                break;
        case 3:
        	if (who->get_legend(TASK_NEWBIE_00, 3))  return;
                cmd1 = sprintf("talk %x# welcome.4\n", getoid(me));
                result =  get_name() + "��\n    ��ո�����������ӣ����ܻ���̫��Ϥ����Ļ����������ɣ���˳�������Ե�������ʯС��һֱ�����ߣ����˵��̣��ҵ��������ϰ壬����������ȡһ��ľ���������ʹ��Ľ�����ģ�\n"
                		ESC "��ȡ����\n" + cmd1 +
                		ESC "�ر�\nCLOSE\n";
                send_user( who, "%c%c%w%s", ':', 3, 6008, result );
                break;
        case 4:
                if (!who->get_legend(TASK_NEWBIE_00, 3)) who->set_legend(TASK_NEWBIE_00, 3);
                send_user( who, "%c%s", '!', "����ȡ������үү�����е�����");
                send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"���ִ�" );
                send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,1,"����үү������" );
                break;
        case 5:
        	if (!who->get_legend(TASK_NEWBIE_00, 4))
        	{
	                result =  get_name() + "��\n    ��ô�����������ϰ岻������Ȼ����ô��û�ù���ѽ���ѵ��ҿ������ˣ�Ӧ�ò����ѽ��\n"
	                		ESC "�뿪\nCLOSE\n";
			send_user( who, "%c%c%w%s", ':', 3, 6008, result );
        		return;
        	}
        	if (who->get_legend(TASK_NEWBIE_00, 5))  return;
                cmd1 = sprintf("talk %x# welcome.6\n", getoid(me));
                result =  get_name() + "��\n    �������ϰ�ʹ��ɣ��Ǻǣ�˵���ˣ����Ǹ�ʹ���ˡ��Ҿ�ϲ�����������˴򽻵������ľ����Ȼ��ֵʲôǮ�����Ƕ�����;�����أ�������ʲô�ã��ҿɲ������㣬�ٺ١����ǰ���ͷ����һ�����ܣ�\n"
                		ESC "�������\n" + cmd1;
                send_user( who, "%c%c%w%s", ':', 3, 6008, result );
                break;
	case 6:
                cmd1 = sprintf("talk %x# welcome.7\n", getoid(me));
                cmd2 = sprintf("talk %x# welcome.8\n", getoid(me));
                cmd3 = sprintf("talk %x# welcome.9\n", getoid(me));
                result =  get_name() + "��\n    ����ѡ��һ����Ʒ��Ϊ������\n"
                		ESC "��ѧ��ľ��\n" + cmd1 +
                		ESC "��ľ��\n" + cmd2 +
                		ESC "��ì\n" + cmd3;
                send_user( who, "%c%c%w%s", ':', 3, 6008, result );
                break;
        case 7:
        case 8:
        case 9:
        	if (who->get_legend(TASK_NEWBIE_00, 4) && !who->get_legend(TASK_NEWBIE_00, 5))
        	{
                	// ��ȥ����үү��ľ��
                	if( !objectp( item = present("����үү��ľ��", who, 1, MAX_CARRY) ) )
                	{
                		send_user( who, "%c%s", '!', "������û������үү��ľ��");
                		return;
                	}
                	item->remove_from_user();
                	destruct(item);
                	switch(flag)
                	{
                	case 7:
                		item = new ("item/01/7200");
                		break;
                	case 8:
                		item = new ("item/01/7500");
                		break;
                	case 9:
                		item = new ("item/01/7400");
                		break;
                	}
                        result = "���� 30 �㾭��";
                        if (item)
                        {
                                if( USER_INVENTORY_D->can_carry(who, item)  >=1 )
                                {
                                        p =item->move(who, -1);
                                        item->add_to_user(p);
		                        result += sprintf("�� %s", item->get_name());
                                }
                                else
                                	destruct(item);
                        }
                        result += "��";
                        send_user( who, "%c%s", ';', result);
                        who->add_exp(30);
                	who->set_legend(TASK_NEWBIE_00, 5);
	                send_user( who, "%c%c%c%w%c", 0x51, 2, 1, TID_NEWBIE_01, 0 );
	                send_user( who, "%c%c%c%w%w%c", 0x51, 2, 2,TID_NEWBIE_01, 1, 0 );
	                "/sys/sys/count"->add_task("����үү������", 1);

                }
                break;
        case 20:
        	if (who->get_legend(TASK_48, 1))  return;
                cmd1 = sprintf("talk %x# welcome.21\n", getoid(me));
                result =  get_name() + "��\n    ��������ִ��⣬�ֲ���һЩ����ֵĶ�����ǲ�����ͨ��С����С�á�������һ�������ƣ����ǻṥ���ˣ�������Щ����������һֱ�������������飬������ܹ�Э���ҳ�����Щ��ֵ�С����ͺ��ˣ�\n    �������ϰ����������һЩ�����ģ���ɱ���ȥ�����ɡ�\n"

                		ESC "��ȡ����\n" + cmd1 +
                		ESC "�ر�\nCLOSE\n";
                send_user( who, "%c%c%w%s", ':', 3, 6008, result );
                break;
        case 21:
        	if (who->get_legend(TASK_48, 1))  return;
		if (who->get_save_2("task.story")>=20)
		{
                	send_user( who, "%c%s", '!', "������ȡ��20���������񣬲�������ȡ�ˣ�");
	                return;
		}
                if (!who->get_legend(TASK_48, 1)) who->set_legend(TASK_48, 1);
                who->delete_save("new_sj");
                send_user( who, "%c%s", '!', "����ȡ��С�����ֵ�����");
                send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_NEWBIE_01,"���ִ�" );
                send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,101,"С������" );
                who->add_save_2("task.story",1);
                break;
	case 26:
                cmd1 = sprintf("talk %x# welcome.27\n", getoid(me));
                cmd2 = sprintf("talk %x# welcome.28\n", getoid(me));
                result =  get_name() + "��\n    ����ѡ��һ����Ʒ��Ϊ������\n"
                		ESC "��װ����\n" + cmd1 +
                		ESC "Ůװ����\n" + cmd2 ;
                send_user( who, "%c%c%w%s", ':', 3, 6008, result );
                break;
        case 27:
        case 28:
        	if (who->get_legend(TASK_NEWBIE_00, 6) && who->get_legend(TASK_NEWBIE_00, 7) && !who->get_legend(TASK_NEWBIE_00, 8))
        	{
                        if (flag==27)
                        	item = new ("/item/01/6000");    // �в���
                        else
                        	item = new ("/item/01/6100");    // Ů����
			result = "���� 80 �㾭��";
                        if (item)
                        {
                                if( USER_INVENTORY_D->can_carry(who, item)  >=2 )
                                {
                                        p =item->move(who, -1);
                                        item->add_to_user(p);
		                        result += sprintf("��%s", item->get_name());
                                }
                                else
                                {
                                	destruct(item);
                                	send_user( who, "%c%s", '!', "������û���㹻�Ŀ�λ��");
                                	return ;
                                }
                        }
                        item = new ("/item/32/3282");    // ����
                        if (item)
                        {
                        	item->set_amount(6);
                                if( USER_INVENTORY_D->can_carry(who, item)  >=1 )
                                {
                                        p =item->move(who, -1);
                                        item->add_to_user(p);
		                        result += sprintf("��%s", item->get_name());
                                }
                                else
                                	destruct(item);
                        }
                        result += "��";
                        send_user( who, "%c%s", ';', result);
                        who->add_exp(80);
                	who->set_legend(TASK_NEWBIE_00, 8);
	                send_user( who, "%c%c%c%w%c", 0x51, 2, 1, TID_NEWBIE_01, 0 );
	                send_user( who, "%c%c%c%w%w%c", 0x51, 2, 2,TID_NEWBIE_01, 2, 0 );
	                "/sys/sys/count"->add_task("С������", 1);
                }
                break;
	case 30:
		if (  get_z(who) != 80 )
			return ;
		if ( who->get_level() >= 30 && !who->get_legend(TASK_NEWBIE_00, 9) )
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s:\n    �������ʦү���Ǹ������������˵��̰���ܻߣ���Ҳ����˵���Ǹ��ù٣����˲������˳��޵ĺ��£�������Щ������ȴ�Ӳ�Ϊ�Լ����壬��˵������ֲ��ٷ�ͽ��ʦү������Ѱ�˰�æ�أ���ȥ�����ɣ����������������ţ�һֱ��ǰ�ߣ������ҵ��ø��ˡ�\n"ESC"��ȡ����\ntalk %x# welcome.31\n"ESC"�뿪",me->get_name(),getoid(me)));
		else if ( !who->get_legend(TASK_NEWBIE_00, 10) )
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s:\n    ��ûȥ�ݷ�ʦү���㲻���ÿ�ϧ���ѵ����һ�㶼��������������һ����������㲻���ʶ��ʶ�������Ǻη���ʥ��\n"ESC"�뿪",me->get_name()));
		break;
	case 31:
		if (  get_z(who) != 80 )
			return ;
		if (who->get_level()>=30&&!who->get_legend(TASK_NEWBIE_00, 9) )
		{
			who->set_legend(TASK_NEWBIE_00, 9);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"�ܹ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,3,"�ݷ�ʦү" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�ݷ�ʦү");
		}
		break;
	case 32:
		if (  get_z(who) != 80 )
			return ;
		if ( !who->get_legend(TASK_NEWBIE_00, 11) )
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s:\n    ����ͷ��������ӵ�һ�����£�����Ҳ��������˵����Ϊ���������ˣ���������׽����Щ�ˣ����뿴�������������ˣ��ǽ��Ϳ϶����٣���ȥ�˿ɵû���㣬������ͷһ��С��˼������Ͳ�����˵�˰ɡ�����ͷ�ܹ����ڵ���վ�Աߣ���ͦ���ģ���ú����Ұɣ�\n"ESC"��ȡ����\ntalk %x# welcome.33\n"ESC"�뿪",me->get_name(),getoid(me)));
		else if ( !who->get_legend(TASK_NEWBIE_00, 12) )
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s:\n    �ף�����ô��ûȥ����ͷ��ѽ��ȥ���˿ɲ��ã���ʱ����¶��ñ��˸����ˣ��㲻��ʧȥ��һ�η��ƵĻ�����\n"ESC"�뿪",me->get_name()));
		break;
	case 33:
		if (  get_z(who) != 80 )
			return ;
		if (who->get_level()>=10&&!who->get_legend(TASK_NEWBIE_00, 11) )
		{
			who->set_legend(TASK_NEWBIE_00, 11);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"�ܹ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,1,"����ͷ������" );
		}
		break;
	case 34:
		if (  get_z(who) != 80 )
			return ;
		if ( !who->get_legend(TASK_NEWBIE_00, 13) )
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s:\n    ξ������ͷ���Ǹ��ýٷ��ŷ�ɥ�����������ʱ����һ���ú����������ڻ�����û������������ʹ��ˣ����Լ�����һ���ھ֣�������Ʋ��ã���˵������̫�ã����ֲ�������ȥ�������ܲ��ܰ���æ���ǵ��ˣ����ھֽ������ھ֣������ҵ���������\n"ESC"��ȡ����\ntalk %x# welcome.35\n"ESC"�뿪",me->get_name(),getoid(me)));
		else if ( !who->get_legend(TASK_NEWBIE_00, 14) )
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s:\n    ������ξ������ͷ�����Ӿ�֪�������ú��ɣ�ʲô���㻹û��������������ȥ����������������Ҫ�г徢ѽ����Ҳ��ξ������ͷ����˵��һ�仰��\n"ESC"�뿪",me->get_name()));
		break;
	case 35:
		if (  get_z(who) != 80 )
			return ;
		if (who->get_level()>=30&&!who->get_legend(TASK_NEWBIE_00, 13) )
		{
			who->set_legend(TASK_NEWBIE_00, 13);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"�ܹ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,2,"��ξ������ͷ̸̸" );
		}

		break;
	case 36:
		if (  get_z(who) != 80 )
			return ;
		if ( who->get_legend(TASK_NEWBIE_01, 23) && !who->get_legend(TASK_NEWBIE_01, 24) && get_z(who) == 80 )
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    Ŷ�������ˡ���������ʵҲû������飬ֻ������������㣬�ܹ�����ر����ִ�Ҫ�㣬��Ӧ�ð�Ŀ���Զһ��Ŷ��Ʃ��˵���ܹ���ʦү��ξ������ͷ������ͷ�ȣ����ǿɶ����˲���Ĵ�����ѽ��\n"ESC"�������\ntalk %x# welcome.37\n"ESC"�뿪",me->get_name(),getoid(me)));
		break;
	case 37:
		if (  get_z(who) != 80 )
			return ;
		if ( who->get_legend(TASK_NEWBIE_01, 23) && !who->get_legend(TASK_NEWBIE_01, 24) && get_z(who) == 80 )
		{
			who->set_legend(TASK_NEWBIE_01, 24);
			who->add_exp(250);
			who->add_potential(30);
			who->add_cash(5000);
			send_user(who,"%c%s",';',"�����Ļ��� ���� 250 Ǳ�� 30 ��Ǯ 5000 ");
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_NEWBIE_01,13,"" );
		}
		break;
        case 40:
		x = (time() - 4 * 24*3600+8*3600) / (7*24*3600);
		if (who->get_save_2("double_time.week")!=x)
		{
			who->set_save_2("double_time.week", x);
			who->set_save_2("double_time.time", 0);		//˫
			who->set_save_2("double_time.time1", 0);	//ս����
			who->set_save_2("double_time.time2", 0);	//ս���Ž�
			who->set_save_2("double_time.time3", 0);
			who->set_save_2("double_time.freeze", 0);	//�����˫��ʱ��
		}
		if (who->get_save_2("double_time.time")>=8)
		{
			y = 7*24*3600 - ((time() - 4 * 24*3600+8*3600) % (7*24*3600));
			if (y<24*3600)
			{
			        send_user( who, "%c%c%w%s", ':', 3, 6008,
			        	sprintf("%s��\n     ����������Ѿ��ۻ���ȡ�����ĸ�Сʱ˫������Ľ���ʱ���ˣ��㻹�ǵ�%dСʱ��������ȡ�ɡ� \n"
			                ESC "�ر�\nCLOSE\n", me->get_name(), y/3600 ) );
			}
			else
			{
			        send_user( who, "%c%c%w%s", ':', 3, 6008,
			        	sprintf("%s��\n     ����������Ѿ��ۻ���ȡ�����ĸ�Сʱ˫������Ľ���ʱ���ˣ��㻹�ǵ�%d���������ȡ�ɡ� \n"
			                ESC "�ر�\nCLOSE\n", me->get_name(), y / (24*3600) ) );
			}
			return;
		}
                cmd1 = sprintf("talk %x# welcome.41\n", getoid(me));
                cmd2 = sprintf("talk %x# welcome.42\n", getoid(me));
                cmd3 = sprintf("talk %x# welcome.43\n", getoid(me));
                result =  get_name() + "��\n    �ҿ��������������������������ȼ�����һ����ʱ��֮���������������ܻ�õľ�����Ǳ�ܽ������Ǽӱ��ġ��㻹������ȡ" + sprintf("%d",(8-who->get_save_2("double_time.time"))*30 )+ " ���ӵ�˫��ʱ�䡣��ô���ڴ�����ѡ��һ���ʺ��Լ�������ʱ��ɡ�\n"
                		ESC "һ��Сʱ\n" + cmd1 +
                		ESC "����Сʱ\n" + cmd2 +
                		ESC "�ĸ�Сʱ\n" + cmd3 +
                		ESC "�ر�\nCLOSE\n";
                send_user( who, "%c%s", ':', result);
                break;
	case 43:
		p += 4;
	case 42:
		p += 2;
	case 41:
		p += 2;
		i = gone_time( who->get_login_time() );
		x = (time() - 4 * 24*3600+8*3600) / (7*24*3600);
		if (who->get_save_2("double_time.week")!=x)
		{
			who->set_save_2("double_time.week", x);
			who->set_save_2("double_time.time", 0);		//˫
			who->set_save_2("double_time.time1", 0);	//ս����
			who->set_save_2("double_time.time2", 0);	//ս���Ž�
			who->set_save_2("double_time.time3", 0);
			who->set_save_2("double_time.freeze", 0);	//�����˫��ʱ��
		}
		if (who->get_save_2("double_time.freeze")>0)
		{
		        send_user( who, "%c%c%w%s", ':', 3, 6008,
		        	sprintf("%s��\n     ���"HIR"˫������ʱ���Ѿ�����"NOR"����������״̬������ȡ�����˫������ɡ�\n"
		                ESC "�ر�\nCLOSE\n", me->get_name() ) );
			return;
		}				
		if (who->get_save_2("double_time.time")>=8)
		{
			y = 7*24*3600 - ((time() - 4 * 24*3600+8*3600) % (7*24*3600));
			if (y<24*3600)
			{
			        send_user( who, "%c%c%w%s", ':', 3, 6008,
			        	sprintf("%s��\n     ����������Ѿ��ۻ���ȡ�����ĸ�Сʱ˫������Ľ���ʱ���ˣ��㻹�ǵ�%dСʱ��������ȡ�ɡ� \n"
			                ESC "�ر�\nCLOSE\n", me->get_name(), y/3600 ) );
			}
			else
			{
			        send_user( who, "%c%c%w%s", ':', 3, 6008,
			        	sprintf("%s��\n     ����������Ѿ��ۻ���ȡ�����ĸ�Сʱ˫������Ľ���ʱ���ˣ��㻹�ǵ�%d���������ȡ�ɡ� \n"
			                ESC "�ر�\nCLOSE\n", me->get_name(), y / (24*3600) ) );
			}
			return;
		}
		if ( who->get_online_rate() == 50 )
		{
			send_user(who,"%c%s",'!',"ƣ����Ϸʱ���ֹ��ȡ˫�����顣");
			return ;	
		}
		else if ( who->get_online_rate() == 0 )
		{
			send_user(who,"%c%s",'!',"��������Ϸʱ���ֹ��ȡ˫�����顣");
			return ;	
		}		
		if (who->get_save_2("double_time.time")+p>8)
		{
		        p = 8 - who->get_save_2("double_time.time");
		}
		send_user( who, "%c%c%w%s", ':', 3, 6008,
			sprintf("%s��\n     ����ȡ�� %d ���ӵ�˫�����齱��ʱ�䣬�úð��հɡ�\n"
		        ESC "�ر�\nCLOSE\n", me->get_name(), p * 30 ) );
		who->add_save_2("double_time.time", p);
		p *= 1800;
		if ( i+ who->get_game_time()<who->get_double_time())
			who->set_double_time(who->get_double_time()+p);
		else
			who->set_double_time(i+ who->get_game_time()+p);
		send_user( who, "%c%c%w%s", ':', 3, 6008,
			sprintf("%s��\n     ���Ѿ��ۼ���ȡ��%d���ӵ�˫������ʱ�䣬�úð��հɡ�\n"
		        ESC "�ر�\nCLOSE\n", me->get_name(), (who->get_double_time()-i-who->get_game_time()) / 60 ) );			
		send_user( who, "%c%c%c%w%s", 0x51, 1, 1,0001,"��Ϸ����" );
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "˫��ʱ��" );
		"/sys/task/task"->send_task_intro(who, 1, 1, 1);
		"/quest/help"->send_help_tips(who, 3);
		"/sys/task/task"->send_task_intro(who, 1, 1, 1);
		break;
	case 50:
		if (MAIN_D->get_host_type()==6012)
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s:\n    ������ʱû�п��š�",me->get_name() ));
			return;
		}
		if ( who->get_level() >= 40 && !who->get_legend(TASK_40,5) )
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s:\n    ������Ҫ��֮�Žǣ���������֮�Žǣ��ƺ�ֻʣ���˴�˵����\n    �ڼ�ʮ��ǰ����һ��������˼ң�����ӵ��һ�Ž���������ʧ�������ա��������Žǡ�����ս�ң��¹���Ǩ�������˼ҵĺ��ӳ����ˣ�ȴ����˽����ϵĶ����������һ���л��в����ٲ���ˮ��������Դ�����������Ӵ˲��ٹ��ʽ���֮�¡�\n    ���룬���������ǲ��ݺ��ӵģ�������뽨���ȥ������ʿ�ɣ��������ϴ���������������һ���Žǣ���Ȼ����Žǻ���Ҫ�����ӹ�����ܳ�Ϊ��֮�Žǣ�����ȥ�����Ķ���ɽ���ҵ����ɡ�\n"ESC"��������\ntalk %x# welcome.51\n"ESC"�뿪",me->get_name(),getoid(me)));
		break;
	case 51:
		if (MAIN_D->get_host_type()==6012)
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s:\n    ������ʱû�п��š�",me->get_name() ));
			return;
		}
		if ( who->get_level() >= 40 && !who->get_legend(TASK_40,5) )
		{
        		who->set_legend(TASK_40,5);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"�ܹ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,10,"����ĺŽ�" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"����ĺŽ�");
		}
		break;


	case 60:
		i = time();
		if ( !close_val && ((i>iStart2&&i<iFinish2) || open_val) )
			        send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
			        	sprintf("%s��\n    ����ũ�����ڱ���������ͬ������ӣ�������������ǰ����ӡ�����޾�Ȼ�������������ڸ�����������ִ嵽�����ҡ���������Щ��ʿ�����񣬷����������޵�ʱ���ˣ����ڱ��������ڸ������ܱߣ��Ͽ�ȥ�ҵ���Щ��������ȥ�������ޣ�������һ���߸����˷�����Ĵ��ڰɣ�\n"
			                ESC "�������޵Ľ�\ntalk %x# welcome.61\n"
			                ESC "�뿪", me->get_name(), getoid(me) ) );
		break;
	case 61:
		i = time();
		if ( !close_val && ((i>iStart2&&i<iFinish2) || open_val) )
		{
                	if( !objectp( item = present("���޵Ľ�", who, 1, MAX_CARRY) ) )
                	{
			        send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
			        	sprintf("%s��\n    ������û�����޵Ľ�ѽ�����ڸ��������������ޣ���Ͽ�ȥ�ұ����������ޣ�Ȼ�����������ϵĽǻ������Ұɣ�\n"
			                ESC "�뿪", me->get_name(), getoid(me) ) );
                	}
                	else
                	{
			        send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
			        	sprintf("%s��\n    ����������������һ�α����Ǹ����ˣ�����Ҫ������������´��ѽڣ���Ҫ����Ļ���Ҫ����˵ʲô��ѽ���Ǻ�~~\n"
			                ESC "��ϲ����\ntalk %x# welcome.62\n"
			                ESC "���綫��\ntalk %x# welcome.62\n"
			                ESC "��������\ntalk %x# welcome.62\n"
			                ESC "ʥ������\ntalk %x# welcome.63\n", me->get_name(), getoid(me), getoid(me), getoid(me), getoid(me) ) );
			}
		}
		break;
	case 62:
		i = time();
		if ( !close_val && ((i>iStart2&&i<iFinish2) || open_val) )
		{


                	if( !objectp( item = present("���޵Ľ�", who, 1, MAX_CARRY) ) )
                	{
                		send_user( who, "%c%s", '!', "������û�����޵Ľ�");
                		return;
                	}
                       	item2 = new ("/item/04/0434");    // �����
                        if (item2)
                        {
                                if( USER_INVENTORY_D->can_carry(who, item2)  >=1 )
                                {
                                        p =item2->move(who, -1);
                                        item2->add_to_user(p);
                                }
                                else
                                {
                                	destruct(item2);
				        send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
			        	sprintf("%s��\n    ������������������Ų����ˣ��������Ļ���ȥ�ڸ���λ�����ɣ�\n"
			                ESC "ȷ��", me->get_name(), getoid(me) ) );
                                	return ;
                                }
                        }
                	// ��ȥ���޵Ľ�һֻ
	                item->add_amount(-1);
			        send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
			        	sprintf("%s��\n    �����������������Ҹ�������������үүҲףԸ�����µ�һ������������⡣\n"
			                ESC "ȷ��", me->get_name(), getoid(me) ) );
	                send_user( who, "%c%s", '!', "��ú��");
		}
		break;
	case 63:
		i = time();
		if ( !close_val && ((i>iStart2&&i<iFinish2) || open_val) )
		{


                	if( !objectp( item = present("���޵Ľ�", who, 1, MAX_CARRY) ) )
                	{
                		send_user( who, "%c%s", '!', "������û�����޵Ľ�");
                		return;
                	}
                       	item2 = new ("/item/04/0434");    // �����
                        if (item2)
                        {
                                if( USER_INVENTORY_D->can_carry(who, item2)  >=1 )
                                {
                                        p =item2->move(who, -1);
                                        item2->add_to_user(p);
                                }
                                else
                                {
                                	destruct(item2);
				        send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
			        	sprintf("%s��\n    ������������������Ų����ˣ��������Ļ���ȥ�ڸ���λ�����ɣ�\n"
			                ESC "ȷ��", me->get_name(), getoid(me) ) );
                                	return ;
                                }
                        }
                	// ��ȥ���޵Ľ�һֻ
	                item->add_amount(-1);
//                	item->remove_from_user();
//                	destruct(item);
			        send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
			        	sprintf("%s��\n    ���ڿɲ���ʥ����Ŷ������˵��������û�к���ġ�������ϣ�������Ҷ��������ģ����Ҳ�Ѻ������ɣ�\n"
			                ESC "ȷ��", me->get_name(), getoid(me) ) );
                	send_user( who, "%c%s", '!', "��ú��");
		}
		break;
	case 70:
                cmd1 = sprintf( "talk %x# welcome.71\n", getoid( me ) );
                cmd2 = sprintf( "talk %x# welcome.72\n", getoid( me ) );
                result =  get_name() + "��\n    ����������"HIR"���µ�������ɹ��׵�"NOR"��ȡ�����˫������ʱ�䡣����"HIR"һ�����ֻ�ܻ�ȡ3�Σ�ÿ��һСʱ"NOR"����ǧ������ⱦ��Ļ���Ŷ��\n" ;
                result += ESC "3�㹦�»�ȡ1Сʱ˫������\n" + cmd1 ;
                result += ESC "3�����ɹ��׻�ȡ1Сʱ˫������\n" + cmd2 ;
                result += ESC "�뿪\nCLOSE\n";
                send_user( who, "%c%c%w%s", ':', 3, 6008, result);
		break;
	case 71:
	case 72:
		i = gone_time( who->get_login_time() );
		if (who->get_save_2("double_time.freeze")>0)
		{
		        send_user( who, "%c%c%w%s", ':', 3, 6008,
		        	sprintf("%s��\n     ���"HIR"˫������ʱ���Ѿ�����"NOR"����������״̬������ȡ�����˫������ɡ�\n"
		                ESC "�ر�\nCLOSE\n", me->get_name() ) );
			return;
		}				
		if ( who->get_online_rate() == 50 )
		{
			send_user(who,"%c%s",'!',"ƣ����Ϸʱ���ֹ��ȡ˫�����顣");
			return ;	
		}
		else if ( who->get_online_rate() == 0 )
		{
			send_user(who,"%c%s",'!',"��������Ϸʱ���ֹ��ȡ˫�����顣");
			return ;	
		}
		if (who->get_save_2("double_time.time3")>=3)
		{
		        send_user( who, "%c%c%w%s", ':', 3, 6008,
		        	sprintf("%s��\n     �㱾���Ѿ�û��ʣ��Ķ���˫������ʱ���ˣ����ǵ�����һ�ٹ����ɡ�\n"
		                ESC "�ر�\nCLOSE\n", me->get_name() ) );
			return;
		}
		if (flag==71)
		{
			if (who->get_bonus() / 10<3)
			{
			        send_user( who, "%c%c%w%s", ':', 3, 6008,
			        	sprintf("%s��\n     ��Ĺ��º�����3�㡣��ù��µ�ķ�����������50��֮����30�����µ������������������ͽ�ܳ�ʦ֮��Ҳ�ܻ�ò��ٵĹ��µ㡣\n"
			                ESC "�ر�\nCLOSE\n", me->get_name() ) );
				return;
			}
			who->add_bonus(-30);
		}
		else
		{
			if (who->get_fam_contribute()<3)
			{
			        send_user( who, "%c%c%w%s", ':', 3, 6008,
			        	sprintf("%s��\n     ������ɹ��׵㲻��3�㡣������ɹ��׵��Ψһ;�������������ʦ�����и��������ÿ��ֻҪ���ڷܵ����ʦ�����񣬱�ɻ����Ӧ�����ɹ��׵㡣\n"
			                ESC "�ر�\nCLOSE\n", me->get_name() ) );
				return;
			}
			who->set_fam_contribute(who->get_fam_contribute()-3);
		}
		who->add_save_2("double_time.time3", 1);
		p = 3600;
		if ( i+ who->get_game_time()<who->get_double_time())
			who->set_double_time(who->get_double_time()+p);
		else
			who->set_double_time(i+ who->get_game_time()+p);
		send_user( who, "%c%c%c%w%s", 0x51, 1, 1,0001,"��Ϸ����" );
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "˫��ʱ��" );
		"/sys/task/task"->send_task_intro(who, 1, 1, 1);
		"/quest/help"->send_help_tips(who, 3);
		"/sys/task/task"->send_task_intro(who, 1, 1, 1);
		p = who->get_save_2("double_time.time3");
		if (p<3)
			result =  sprintf(get_name() + "��\n    ���Ѿ��ɹ���ȡ��1��Сʱ�ľ���˫��ʱ�䣬�㱾�ܻ�ʣ��"HIR"%dСʱ"NOR"�Ķ���˫��ʱ�����ȡ���úð��հɡ�\n", 3 - p);
		else
			result =  get_name() + "��\n    ���Ѿ��ɹ���ȡ��1��Сʱ�ľ���˫��ʱ�䣬�㱾���Ѿ�û�ж���˫��ʱ�����ȡ�ˣ��úð�������һ��Сʱ˫������ʱ��ɡ�\n" ;
		result += ESC "�뿪\nCLOSE\n";
		send_user( who, "%c%c%w%s", ':', 3, 6008, result);
		break;
	case 80:
	        send_user( who, "%c%c%w%s", ':', 3, 6008,
	        	sprintf("%s��\n     VIP����Ӣ��Very Important Person����д����˼���Ǻ���Ҫ���ˣ�ͨ��˵�ġ�ҪԱ����������Ϊʲô��Ӣ�ģ������������֪���ģ���֪����ͨ�Ž����⣬����ȥδ��������ս��������ʱ������������������VIP��һ������\n"
	                ESC "VIP��ʲô�ô���\ntalk %x# welcome.81\n"
	                ESC "��������ΪVIP��\ntalk %x# welcome.82\n"
	                ESC "��ѯ�ҵ�VIP�󶨵���ʱ��\ntalk %x# welcome.83\n"
	                ESC "�ر�\nCLOSE\n", me->get_name(),getoid(me),getoid(me),getoid(me) ) );
		
		break;	
	case 100:
		if ( who->get_online_rate() == 50 )
		{
			send_user(who,"%c%s",'!',"ƣ����Ϸʱ���ֹ���˫�����鶳�ᡣ");
			return ;	
		}
		else if ( who->get_online_rate() == 0 )
		{
			send_user(who,"%c%s",'!',"��������Ϸʱ���ֹ���˫�����鶳�ᡣ");
			return ;	
		}
		result =  get_name() + "��\n    ��ȷ������Ҫ���˫�����鶳���𣿵�Ȼ������Ҫ����˫������Ļ�������ʱ�������ҡ�\n";
		result += ESC "����ҽ��˫�����鶳��\n"+sprintf( "talk %x# welcome.101\n", getoid( me ) );
		result += ESC "�뿪\nCLOSE\n";
		send_user( who, "%c%c%w%s", ':', 3, 6008, result);
		break;			
	case 101:
		if ( who->get_online_rate() == 50 )
		{
			send_user(who,"%c%s",'!',"ƣ����Ϸʱ���ֹ���˫�����鶳�ᡣ");
			return ;	
		}
		else if ( who->get_online_rate() == 0 )
		{
			send_user(who,"%c%s",'!',"��������Ϸʱ���ֹ���˫�����鶳�ᡣ");
			return ;	
		}
		if (who->get_save_2("double_time.freeze")>0)
		{
			i = gone_time( who->get_login_time() );
			if ( i+ who->get_game_time()<who->get_double_time())
				who->set_double_time(who->get_double_time()+who->get_save_2("double_time.freeze"));
			else
				who->set_double_time(i+ who->get_game_time()+who->get_save_2("double_time.freeze"));
			who->set_save_2("double_time.freeze", 0);
			result =  get_name() + sprintf("��\n    ���Ѿ��ɹ������˫������Ķ���ʱ�䣬�������Ѿ���ȡ��"HIR" %d�� "NOR"��˫������ʱ�䣬�����Ҫ����Ļ�����ʱ�������ҡ�\n", who->get_double_time() -i -who->get_game_time());
			result += ESC "�뿪\nCLOSE\n";
			send_user( who, "%c%c%w%s", ':', 3, 6008, result);			
			send_user( who, "%c%c%c%w%s", 0x51, 1, 1,0001,"��Ϸ����" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "˫��ʱ��" );
			"/sys/task/task"->send_task_intro(who, 1, 1, 1);			
		}
		break;
	case 102:	//	ս���������ȡ����
		if(objectp(item = "/quest/zg_dict"->want_an_zgdict(me,who))) {
			p = item->move(who,-1);
			item->add_to_user(p);
			send_user(who,"%c%s",'!',"�������ս�����䡣");
		}
		break;
	case 90:
		result =  get_name() + "��\n    ��ϣ���������˫������ʱ����һ���㵱ǰ��˫������ʱ�䱻���ᣬ��ô����޷�����ȡ�µ�˫������ʱ�䡣��˫������ʱ�䶳��֮����Ҫ�Ļ�������ʱ�������������ｫ�����˫������ʱ��ⶳ��\n    ���������ע�⣬������˫������ʱ�䣬��ֻ��Ϊ��"HIR"���浽ÿ���������23��59�֣�һ�����������ʱ�䣬�����ʱ�佫�ᱻȫ����ա�\n";
		result += ESC "����Ҷ���˫������ʱ��\n"+sprintf( "talk %x# welcome.91\n", getoid( me ) );
		result += ESC "�뿪\nCLOSE\n";
		send_user( who, "%c%c%w%s", ':', 3, 6008, result);
		break;		
	case 91:
		i = gone_time( who->get_login_time() );
		if ( i+ who->get_game_time()<who->get_double_time())
		{
			who->set_save_2("double_time.freeze", who->get_double_time() - i - who->get_game_time() );
			result =  get_name() + sprintf("��\n    ���Ѿ��ɹ�������"HIR" %d�� "NOR"��˫������ʱ�䣬�����Ҫ�ⶳ�Ļ�����ʱ�������ҡ�\n", who->get_double_time() -i -who->get_game_time());
			result += ESC "�뿪\nCLOSE\n";
			send_user( who, "%c%c%w%s", ':', 3, 6008, result);			
			who->set_double_time(0);
			send_user( who, "%c%c%c%w%s", 0x51, 1, 1,0001,"��Ϸ����" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "˫��ʱ��" );
			"/sys/task/task"->send_task_intro(who, 1, 1, 1);						
		}
		break;		
	case 81:
	        send_user( who, "%c%c%w%s", ':', 3, 6008,
	        	sprintf("%s��\n     VIP��ô�ʵ���Ǻܶడ��\n    ���ȣ���ΪVIP�ڼ����ӵ��VIP�ĳ�ν������ͻ��VIP��ӵ��ר��ķ���Ƶ����ר��ĸı䷢����ɫ�����\n    ��Σ�����˫��ʱ�䣻������ӹ̶���������ֵ������ҩƷ��ȴʱ���״̬Ч����ÿ�컹�ܻ��������Ѹ������󲻻����κ���ʧ��ȡ�������ĵȼ����ƣ��������������ڻ��ߵ����Լ��ȼ��εĸ�����\n    �ٴΣ�ÿ���ǰ20��ʦ������Ľ���������ʦүɱ������Ǳ�ܽ����ӱ���VIP����ڶ�����ʱ�ܸ�ȫ�����Ӷ��⾭�顣\n    ���⣬VIP�����ʹ������������Ʒ��ʹ�þ�ʯ����װ����ʹ�ö���ʯ����װ������ʱ���ɹ��ʶ���������\n    ��ѽ����˵�ú��ۣ�������Ϣ��ɡ�����ĺô���Ҳ����ȥ�ٷ���ѯѽ��\n"
	                ESC "��������ΪVIP��\ntalk %x# welcome.82\n"
	                ESC "�ر�\nCLOSE\n", me->get_name(),getoid(me) ) );
		
		break;
	case 82:
	        send_user( who, "%c%c%w%s", ':', 3, 6008,
	        	sprintf("%s��\n     ��ΪVIPô�������ȥ�ٷ���վzg.mop.com ����Ԫ������ս���䱦��VIP�������Ŀ��ѡ����VIP�����Ϳ�������Ľ�ɫID����ˡ�\n    ����Ҫע����ǣ�Ԫ���ǳ����˻��еģ���VIP���빺��Ľ�ɫID��󶨵ģ��ɲ�Ҫ�����ѽ��\n"
	                ESC "��ѯ�ҵ�VIP�󶨵���ʱ��\ntalk %x# welcome.83\n"
	                ESC "�ر�\nCLOSE\n", me->get_name(),getoid(me) ) );
		
		break;
	case 83:
		if ( !who->get_vip() )
		{
			send_user(who,"%c%s",':',sprintf("%s\n    ���ƺ�����VIP��Ա�ء�\n"ESC"�뿪",me->get_name()));
			return ;
		}
		iVipTime = who->get_save_2("vip_package.time");
		mxTime = localtime(iVipTime);
	        send_user( who, "%c%c%w%s", ':', 3, 6008,
	        	sprintf("%s��\n     ��ӭ��������VIP��ʱ�佫������%d-%02d-%02d %02d:%02d:%02d����Ҫʲô������\n"
	                ESC "����VIP˫��ʱ��\ntalk %x# welcome.84\n"
	                ESC "�ر�\nCLOSE\n", me->get_name(),mxTime[TIME_YEAR],mxTime[TIME_MON]+1,mxTime[TIME_MDAY],		mxTime[TIME_HOUR],mxTime[TIME_MIN],mxTime[TIME_SEC],getoid(me) ) );
		
		break;
	case 84:
		if ( !who->get_vip() )
		{
			send_user(who,"%c%s",':',sprintf("%s\n    ���ƺ�����VIP��Ա�ء�\n"ESC"�뿪",me->get_name()));
			return ;
		}
		x = who->get_save_2("vip_package.doubles");
		y = x / 2;
		z = x % 2;
		if ( z )
			cmd1 = sprintf("%s��\n     VIP��ʱ������������ȡVIP˫��ʱ��"HIR"%dСʱ30����"NOR"���������Ƿ�Ҫ��ȡVIP˫��ʱ�䣿\n",me->get_name(),y);
	        else   	
			cmd1 = sprintf("%s��\n     VIP��ʱ������������ȡVIP˫��ʱ��"HIR"%dСʱ"NOR"���������Ƿ�Ҫ��ȡVIP˫��ʱ�䣿\n",me->get_name(),y);
	                	
	        send_user( who, "%c%c%w%s", ':', 3, 6008,
	        	sprintf(cmd1+
	                ESC "��ȡ��ʮ����VIP˫��ʱ��\ntalk %x# welcome.85\n"
	                ESC "��ȡһСʱVIP˫��ʱ��\ntalk %x# welcome.86\n"
	                ESC "��ȡ��СʱVIP˫��ʱ��\ntalk %x# welcome.87\n"
	                ESC "�ر�\nCLOSE\n",getoid(me),getoid(me),getoid(me) ) );
		break;
	case 87:
		p += 2;
	case 86:
		p += 1;
	case 85:
		p += 1;
		if ( !who->get_vip() )
		{
			send_user(who,"%c%s",':',sprintf("%s\n    ���ƺ�����VIP��Ա�ء�\n"ESC"�뿪",me->get_name()));
			return ;
		}
		if ( who->get_save_2("vip_package.doubles") < p )
		{
			send_user(who,"%c%s",':',sprintf("%s\n    ����VIP˫��ʱ���Ѿ������ˡ�\n"ESC"�뿪",me->get_name()));
			return ;
		}
		i = gone_time( who->get_login_time() );
		x = (time() - 4 * 24*3600+8*3600) / (7*24*3600);
		if (who->get_save_2("double_time.week")!=x)
		{
			who->set_save_2("double_time.week", x);
			who->set_save_2("double_time.time", 0);		//˫
			who->set_save_2("double_time.time1", 0);	//ս����
			who->set_save_2("double_time.time2", 0);	//ս���Ž�
			who->set_save_2("double_time.time3", 0);
		}
		who->add_save_2("vip_package.doubles",-p);
		send_user( who, "%c%c%w%s", ':', 3, 6008,
			sprintf("%s��\n     ����ȡ�� %d ���ӵ�VIP˫�����齱��ʱ�䣬�úð��հɡ�\n"
		        ESC "�ر�\nCLOSE\n", me->get_name(), p * 30 ) );

		p *= 1800;
	        if ( i+ who->get_game_time()<who->get_double_time())
	        	who->set_double_time(who->get_double_time()+p);
		else
			who->set_double_time(i+ who->get_game_time()+p);		
		send_user( who, "%c%c%c%w%c", 0x51, 1, 1,0001, 0 );
		send_user( who, "%c%c%c%w%w%c", 0x51, 1, 2, 0001, 1, 0 );
		send_user( who, "%c%c%c%w%s", 0x51, 1, 1,0001,"��Ϸ����" );
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "˫��ʱ��" );
		"/quest/help"->send_help_tips(who, 3);
		"/sys/task/task"->send_task_intro(who, 1, 1, 1);
		break;
	case 88:
	        send_user( who, "%c%c%w%s", ':', 3, 6008,
	        	sprintf("%s��\n     Ϊ�˻�����ս��������ҺͰ���������ң�����������������"HIR"VIP���ð�"NOR"�����͵ķ���\n    ֻҪ�κεȼ�����30�������ϵ���ң�����������������ȡһ��"HIR"VIP���ð�"NOR"����Ȼ����Ϊ�����ð�����������VIP������һ�����\n    һ�����ð���ʹ��ʱ��ֻ��"HIR"3�죨����ȡ��ʼ���㣩��\n    ���������ð��������õ�����ʱ���ڣ���������������ۼ���ȡ�����"HIR"10��Сʱ˫������ʱ�䡣\n    ��������������ܳ�Ʒ��װ�������Ͷ���װ����ʱ��"HIR"��������5���ĳɹ����ʡ�\n"
	                ESC HIY"��ȡVIP���ð�\ntalk %x# welcome.89\n"
	                ESC "�ر�\nCLOSE\n", me->get_name(),getoid(me) ) );
		break;
	case 89:
		"item/sell/0061"->give_trial_vip(me,who);
		break;
        case 99:
                cmd1 = sprintf( "talk %x# welcome.1\n", getoid( me ) );
                cmd2 = sprintf( "talk %x# welcome.3\n", getoid( me ) );
                cmd3 = sprintf( "talk %x# welcome.20\n", getoid( me ) );
                cmd4 = sprintf( "talk %x# welcome.30\n", getoid( me ) );
                cmd5 = sprintf( "talk %x# welcome.40\n", getoid( me ) );
                cmd6 = sprintf( "talk %x# welcome.70\n", getoid( me ) );
                cmd7 = sprintf( "talk %x# welcome.100\n", getoid( me ) );
                cmd8 = sprintf( "talk %x# welcome.90\n", getoid( me ) );
                if ( get_z(who) == 80 )
                	result =  get_name() + "��\n    �������ܹ���������������������ܹ������ĵĵط�����ͨ�˴�ģ�ȥ�Ķ����þ������⡣�����������ʲô���֣���̳��֪���ɣ����Ǹ��쵱�������֣�\n" ;
                else
			result =  get_name() + "��\n    ���������������ִ嶼�ᾭ����������ţ���ո�������������϶�ʲô�����˽⣬��Ҫ�Ҹ������һ����\n" ;
		if ( z == 1 || z == 4 ||  z == 7 )
		{
			if (who->get_legend(TASK_NEWBIE_00, 1) && !who->get_legend(TASK_NEWBIE_00, 2) )
				result = result +  ESC +HIY+ "����ʹ��\n" + cmd1;
			if (who->get_legend(TASK_NEWBIE_00, 3) && !who->get_legend(TASK_NEWBIE_00, 5)	)
				result = result +  ESC "����ľ��\n" + sprintf("talk %x# welcome.5\n", getoid( me ));
			if (!who->get_legend(TASK_48, 1))
				result = result +  ESC +HIY+ "С������\n" + cmd3;
		}
		else
		{
//			if (who->get_level()>=30&&(!who->get_legend(TASK_NEWBIE_00, 9)||!who->get_legend(TASK_NEWBIE_00, 10))&& get_z(who) == 80 )
//				result = result + ESC +HIY+ "�ݷ�ʦү\n" + sprintf("talk %x# welcome.30\n", getoid( me ));
//			if (who->get_level()>=10&&(!who->get_legend(TASK_NEWBIE_00, 11)||!who->get_legend(TASK_NEWBIE_00, 12)) && get_z(who) == 80)
//				result = result + ESC +HIY+ "����ͷ������\n" + sprintf("talk %x# welcome.32\n", getoid( me ));
//			if (who->get_level()>=30&&(!who->get_legend(TASK_NEWBIE_00, 13)||!who->get_legend(TASK_NEWBIE_00, 14))&& get_z(who) == 80 )
//				result = result + ESC +HIY+ "��ξ������ͷ̸̸\n" + sprintf("talk %x# welcome.34\n", getoid( me ));
			if ( who->get_legend(TASK_NEWBIE_01, 23) && !who->get_legend(TASK_NEWBIE_01, 24) && get_z(who) == 80 )
				result = result + ESC +HIY+ "�����Ļ���\n" + sprintf("talk %x# welcome.36\n", getoid( me ));
			if ( who->get_level() >= 40 && !who->get_legend(TASK_40,5) )
				result = result + ESC +HIY+ "����Ĵ�˵\n" + sprintf("talk %x# welcome.50\n", getoid( me ));
		}
                if (is_holiday()) result += sprintf( ESC "������ȡ����\n%s\n" , cmd4 );
                result += ESC "��ȡ˫��ʱ��\n" + cmd5 ;
                result += ESC "��ȡ�����˫��ʱ��\n" + cmd6 ;
	        i = gone_time( who->get_login_time() );
		if (who->get_save_2("double_time.freeze")>0)
			result += ESC +HIY+"�����ҵ�˫�����鶳��\n" + cmd7 ;
		else
		if ( i+ who->get_game_time()<who->get_double_time())
			result += ESC HIY"����˫������ʱ��\n" + cmd8 ;
		i = time();
		if ( !close_val && ((i>iStart2&&i<iFinish2) || open_val) )
			result += sprintf(ESC "����үү���ںã�\ntalk %x# welcome.60\n",getoid(me));
                result += sprintf(ESC HIG"VIP��ʲô��\ntalk %x# welcome.80\n",getoid(me));
                result += sprintf(ESC HIG"����VIP˫��ʱ��\ntalk %x# welcome.84\n",getoid(me));
                result += sprintf(ESC HIY"VIP���ð�\ntalk %x# welcome.88\n",getoid(me));
                result += sprintf(ESC "��ȡ��ս�����䡷\ntalk %x# welcome.102\n",getoid(me));
                result += ESC "�뿪\nCLOSE\n";

                send_user( who, "%c%s", ':', result);
                break;
        }
}


int is_holiday()
{
        return 0;
}

//���ô��ڻ�Ŀ����͹ر�
int set_newyear(int open,int close)
{
	open_val = open;
	close_val = close;
	return 1;
}
