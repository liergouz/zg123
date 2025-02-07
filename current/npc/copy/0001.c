#include <npc.h>
#include <ansi.h>
#include <public.h>
#include <time.h>
#include <equip.h>
#include <task.h>

inherit OFFICER;
int host_type;

// ��������ȡ��������
int get_char_picid() { return 5501; }
void do_welcome(string arg);
void do_accept(string arg);
void do_query(string arg);

// ���������촦��
void create()
{
	object me=this_object();
        set_name("������");
        set_2( "talk", ([
                 "welcome"         : (: do_welcome :),
                 "accept"         : (: do_accept :),
                 "query"         : (: do_query :),
        ]) );
        set("legend", ({ 32 }));
        setup();
	host_type = MAIN_D->get_host_type();
}

void do_look(object who)
{
	int id;
	string cmd="";
	object me=this_object();
	id = getoid(me);
	if ( who->get_legend(TASK_2_00,16) && !who->get_legend(TASK_2_00,17) ) 
		cmd = sprintf(ESC HIY "����̸̸\ntalk %x# welcome.11\n",id);
	if ( who->get_legend(TASK_2_00,17) && !who->get_legend(TASK_2_00,18) ) 
		cmd = sprintf(ESC HIY "�ݷ�����\ntalk %x# welcome.13\n",id);
	if ( "sys/sys/count"->get_new_story() == 0 )
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("��������\n    ������ҵõ���һ������������������Ϲ�������澵����������������������Ϊս���������ľ��������ϲ�����౦��Ĳ��ǣ������һ����ϡ��װ���ھ���ǰ�����ٻ��Ļ����Ϳ��Խ���������ľ����ˡ������Ҳ�뵽��������̽�յĻ��������һ������װ�����ң��Ұ���������ͨ�������ͨ���ɣ�\n"+ cmd +ESC"���������\ntalk %x# welcome.1\n"ESC"ʲô�Ƿ�����\ntalk %x# welcome.2\n"ESC"��������\ntalk %x# welcome.3\n"ESC"���������¸ı�\ntalk %x# welcome.20\n"ESC"�뿪",id,id,id,id));
	else
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("��������\n    ������ҵõ���һ������������������Ϲ�������澵����������������������Ϊս���������ľ��������ϲ�����౦��Ĳ��ǣ������һ����ϡ��װ���ھ���ǰ�����ٻ��Ļ����Ϳ��Խ���������ľ����ˡ������Ҳ�뵽��������̽�յĻ��������һ������װ�����ң��Ұ���������ͨ�������ͨ���ɣ�\n"+ cmd +ESC"���������\ntalk %x# welcome.1\n"ESC"ʲô�Ƿ�����\ntalk %x# welcome.2\n"ESC"��������\ntalk %x# welcome.3\n"ESC"���������¸ı�\ntalk %x# welcome.20\n"ESC"������������\ntalk %x# welcome.80\n"ESC"�뿪",id,id,id,id,id));
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
	int flag,i,id,tId,*nXy;
       	object who, item,map;
       	string cTmp,cFile;
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        id = getoid(me);
        switch(flag)
        {
        case 1:
        	tId = who->get_team_id();
        	if ( tId )
        	{
        		map = TEAM_D->get_copy_scene(tId,COPY_MIRROR);
        		if ( map )
        		{
        			if ( who->get_level() < 35 )
        			{
 					send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("��������\n    �������ڵ�ʵ������������������Ǻ�Σ�յģ�����ĵȼ������������ˣ���������ȥ�ɡ�\n"));
        				return ;	
        			}
        			nXy = map->get("exit");
        			who->add_to_scene(map->get_id(),nXy[0],nXy[1]);
        			return ;
        		}	
        	}
 		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("��������\n    ��������������򿪽����������ͨ����Ҫ��ͨ�����ͱ�����һ��15�����ϵ���ϡ��װ���ٻ���Ϊ��ý���������һ�����̶����ϵ�װ�����Ұ�������ٻ���Ϊ��ý��ͨ�������������ͨ���ɣ�������װ�����㶮����\n"ESC"�Ҷ��ã�������ALT+G��"));
        	break;
        case 2:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("��������\n    �������Ǹ��ط���Σ�գ����Ե���ȥ�Ļ���̫�����ˣ������Ҫ����������ӣ�������Ķ�Ա�ȼ����������������Ҳſ�������ȥ������������һ������ֻ����������˽�ȥ��������Ķ����ǲ����Գ�������˵ġ�������ɶ���֮������Ķӳ�������һ����ɫ����ϡװ�����ҾͿ�������ȥ�����������ˡ�\n"ESC"�Ҹø�����ʲô�ȼ���װ����\ntalk %x# welcome.4\n"ESC"������ð����Ҫע��Щʲô��\ntalk %x# welcome.5\n"ESC"�������������ǻ���ʲô��ս��\ntalk %x# welcome.6\n"ESC"�뿪",id,id,id));
        	break;
        case 3:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("��������\n    ���������������Ļ���������ٸ���һ����ϡװ�������ٻ����Ϳ��������������µľ����ˡ�\n"ESC"�뿪",id,));
        	break;
        case 4:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("��������\n    ��ٻ���Ϊ��ý����ϡװ�����ٱ�����15��������ɫ�̶ȵ�װ������������ҵ�װ���ĵȼ��Ǻ���Ҫ����Ϊ��ʲô�ȼ���װ����Ϊ��ý���ͻ����ɶ�Ӧ�ȼ�����ľۼ��ľ������������������ʲô�ȼ������֣���͸����Ҷ�Ӧ�ȼ���װ����Ϊ��ý�ɣ�������Ҳ���ص��ģ���Ϊ����������һЩ�������ϵı���Ҳ�ܲ���������ܴ����������������ϻ�õ�װ��Ҳ���Ժ���ٻ���װ�������ˡ�\n"ESC"����\ntalk %x# welcome.2\n"ESC"�뿪",id,));
        	break;
        case 5:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("��������\n    ��Ϊ��������һ��а�����صĵط��������������������ʱ������Ķ����Žᣬһ�����ھ�������ʧȥ�����ˣ���Ͳ��ٿ��������Ǿ��������ˡ�\n"ESC"����\ntalk %x# welcome.2\n"ESC"�뿪",id,));
        	break;
        case 6:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("��������\n    ��˵�����ӡ��ǰ��������������������������ҵ�����ľ����������������������ྵ����������˵ֻҪ���ܰ�����ľ������������һ���������ͻ��������˵�Ĳ��ǡ���������ǾͿ��Ի��һЩ������ջ��ˣ�\n"ESC"����\ntalk %x# welcome.2\n"ESC"�뿪",id,));
        	break;
        case 7:
        	tId = who->get_team_id();
        	if ( tId )
        	{
        		map = TEAM_D->get_copy_scene(tId,COPY_MIRROR);
        		if ( map )
        		{
        			if ( who->get_level() < 35 )
        			{
 					send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("��������\n    �������ڵ�ʵ������������������Ǻ�Σ�յģ�����ĵȼ������������ˣ���������ȥ�ɡ�\n"));
        				return ;	
        			}
        			nXy = map->get("exit");
        			who->add_to_scene(map->get_id(),nXy[0],nXy[1]);
        			return ;
        		}	
        	}
        	break;
	case 11:
		if ( who->get_legend(TASK_2_00,16) && !who->get_legend(TASK_2_00,17) ) 
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ��Ҳ��˵�˷������Ĵ�˵��û�����������������У����㹻ǿ�Ժ��������ң��ҽ������������ķ�����\n"ESC"�������\ntalk %x# welcome.12\n"ESC"�뿪",me->get_name(),getoid(me)));
		break;
	case 12:
		if ( who->get_legend(TASK_2_00,16) && !who->get_legend(TASK_2_00,17) ) 
		{
			TASK_LEGEND_D->task_finish(who);
			who->set_legend(TASK_2_00,17);
			who->add_exp(300);
			who->add_potential(35);
			who->add_cash(500);
			send_user(who,"%c%s",';',sprintf("�ݷ������� ���� 300 Ǳ�� 35 ��Ǯ 500"));
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,18,"" );
			me->do_welcome(13);
		}
		break;
	case 13:
		if ( who->get_legend(TASK_2_00,17) && !who->get_legend(TASK_2_00,18) ) 
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ս��������Ⱥ�۲������յ��������Ѿ�ʧȥ�˺������µ�������������������˳Ӧ��ʱ���Ƴ�һ�ױ���ϵͳ��ϣ���ܸı��ܹ����ȵ���״����Ҫ������Ȥ��ȥ�������￴����������кô��ġ�˳�Ŵ�·һֱ��ǰ�ߣ��������ھ�ͷ�Ĺ����\n"ESC"��������\ntalk %x# welcome.14\n"ESC"�뿪",me->get_name(),getoid(me)));
		break;		
	case 14:
		if ( who->get_legend(TASK_2_00,17) && !who->get_legend(TASK_2_00,18) ) 
		{
			if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
			who->set_legend(TASK_2_00,18);
			send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_ZHOUGUO,"�ܹ�" );
			send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_ZHOUGUO,19,"�ݷ�����" );
			send_user( who, "%c%s", '!', "�õ����� "HIY"�ݷ�����");
		}
		break;	
	case 20:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("��������\n    ���������������������ڵĸ�����ʿ����Ŭ�������������ڵ������Ѿ���ʼ���������ڣ����ǿ���ʹ�ø��ͼ���װ���򿪸��߼��ķ����������ˡ������ڿ�ʼ���������Ҫ��һ����Ӧ�ȼ��ľ�����ֻҪ�����ұ�����Ҫ�򿪵���Ӧ�ȼ������20����װ���Ϳ����ˡ�\n"ESC"���徵��������\ntalk %x# welcome.21\n"ESC"�����ڻ��������ı���\ntalk %x# welcome.22\n"ESC"����\ntalk %x# welcome.2\n"ESC"�뿪",id,id,id));
		break;
	case 21:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("��������\n    ���ڷ������ڵ����������ˣ����Դ����ڿ�ʼ���������Ҫ��һ����Ӧ�ȼ��ľ�����ֻҪ�����ұ�����Ҫ�򿪵���Ӧ�ȼ������20����װ���Ϳ����ˡ�������Ҫ��һ��50���ľ���Ļ�����ֻҪ����һ��30������ɫ�̶�����װ���Ϳ����ˡ����ǣ��Ұ���򿪵ľ���ĵȼ��ǲ��ᳬ��������ĵȼ��ġ�\n"ESC"����\ntalk %x# welcome.20\n"ESC"�뿪",id,));
		break;
	case 22:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("��������\n    ����˵���еĽ��뿪���������ʿ��������ڰѷ������ڵľ���ȫ�������������һЩ��Ϊ���������족��ǿ����������˵��Щ��������ͬ�����зǳ����ı�������˽������ϢӦ�ò��٣���ʿ�㲻��ȥ����һ�¡�\n"ESC"����\ntalk %x# welcome.20\n"ESC"�뿪",id,));
		break;
	case 80:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("��������\n    ��˵�ڷ��������̲���6���������˵��������������������Ӧ�Ĳ��ϣ��ҾͿ��԰���������Щ����������\n"ESC"�����񳿱���\ntalk %x# welcome.81\n"ESC"�������𱦵�\ntalk %x# welcome.82\n"ESC"�����������ǹ\ntalk %x# welcome.83\n"ESC"����Ǭ���޼���\ntalk %x# welcome.84\n"ESC"�����̻��»�\ntalk %x# welcome.85\n"ESC"����Ӣ��ȭ��\ntalk %x# welcome.86\n"ESC"�뿪",id,id,id,id,id,id,));
		break;
	case 81:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("��������\n    �����񳿱�������Ҫ��������һ�ѡ�³�౦ʯ30�����ɽ���ʯ20����ŷұ��ʯ	20���������ӵ���㹻�Ĳ��ϣ��ҾͿ��԰��������񳿱�����\n"ESC"���ɲ���\ntalk %x# welcome.811\n"ESC"��������������ҵ���\ntalk %x# welcome.812\n"ESC"�뿪",id,id));
		break;
	case 82:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("��������\n    �������𱦵�����Ҫ�����ǽ�һ�ѡ�³�౦ʯ30�����ɽ���ʯ20����ŷұ��ʯ	20���������ӵ���㹻�Ĳ��ϣ��ҾͿ��԰����������𱦵���\n"ESC"���ɲ���\ntalk %x# welcome.821\n"ESC"��������������ҵ���\ntalk %x# welcome.822\n"ESC"�뿪",id,id));
		break;
	case 83:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("��������\n    �����������ǹ����Ҫ�����ǳ�ӧǹһ�ѡ�³�౦ʯ30�����ɽ���ʯ20����ŷұ��ʯ	20���������ӵ���㹻�Ĳ��ϣ��ҾͿ��԰��������������ǹ��\n"ESC"���ɲ���\ntalk %x# welcome.831\n"ESC"��������������ҵ���\ntalk %x# welcome.832\n"ESC"�뿪",id,id));
		break;				
	case 84:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("��������\n    ����Ǭ���޼�������Ҫ�����ǹŷ���һ����³�౦ʯ30�����ɽ���ʯ20����ŷұ��ʯ	20���������ӵ���㹻�Ĳ��ϣ��ҾͿ��԰�������Ǭ���޼�����\n"ESC"���ɲ���\ntalk %x# welcome.841\n"ESC"��������������ҵ���\ntalk %x# welcome.842\n"ESC"�뿪",id,id));
		break;
	case 85:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("��������\n    �����̻��»�����Ҫ�������»�һ�ѡ�³�౦ʯ30�����ɽ���ʯ20����ŷұ��ʯ	20���������ӵ���㹻�Ĳ��ϣ��ҾͿ��԰��������̻��»���\n"ESC"���ɲ���\ntalk %x# welcome.851\n"ESC"��������������ҵ���\ntalk %x# welcome.852\n"ESC"�뿪",id,id));
		break;
	case 86:
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("��������\n    ����Ӣ��ȭ�У���Ҫ������ʯ��ȭ��һ�ס�³�౦ʯ30�����ɽ���ʯ20����ŷұ��ʯ	20���������ӵ���㹻�Ĳ��ϣ��ҾͿ��԰�������Ӣ��ȭ�С�\n"ESC"���ɲ���\ntalk %x# welcome.861\n"ESC"��������������ҵ���\ntalk %x# welcome.862\n"ESC"�뿪",id,id));
		break;		
	case 811:
	case 821:
	case 831:
	case 841:
	case 851:
	case 861:
		if ( flag == 811 )
		{
			cTmp = "��";
			cFile = "item/73/9075";
		}
		else if ( flag == 821 )
		{
			cTmp = "��";
			cFile = "item/72/9075";
		}
		else if ( flag == 831 )
		{
			cTmp = "��ӧǹ";
			cFile = "item/74/9075";
		}
		else if ( flag == 841 )
		{
			cTmp = "�ŷ���";
			cFile = "item/75/9075";
		}
		else if ( flag == 851 )
		{
			cTmp = "�»�";
			cFile = "item/71/9075";
		}
		else if ( flag == 861 )
		{
			cTmp = "ʯ��ȭ��";
			cFile = "item/70/9075";
		}
		if ( TASK_LEGEND_D->check_task_item_amount(who,cTmp) == 0 ||
			TASK_LEGEND_D->check_task_item_amount(who,"³�౦ʯ") < 30 ||
			TASK_LEGEND_D->check_task_item_amount(who,"�ɽ���ʯ") < 20 ||
			TASK_LEGEND_D->check_task_item_amount(who,"ŷұ��ʯ") < 20 )
		{
			send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("��������\n    ����%s��Ҫ%sһ�ѣ�³�౦ʯ30�����ɽ���ʯ20����ŷұ��ʯ20���������Ϻ���û���㹻�Ĳ��ϰɣ�\n"ESC"�뿪",cFile->get_name(),cTmp));
			return ;	
		}
		TASK_LEGEND_D->check_task_item1(who,cTmp,1);
		TASK_LEGEND_D->check_task_item1(who,"³�౦ʯ",30);
		TASK_LEGEND_D->check_task_item1(who,"�ɽ���ʯ",20);
		TASK_LEGEND_D->check_task_item1(who,"ŷұ��ʯ",20);
		item = new(cFile);
		item->set_hide(0);
		item->set_bind(4);
		i = item->move(who,-1);
		if ( !i )
		{
			destruct(item);
			return ;	
		}
		item->add_to_user(i);
		send_user(who,"%c%s",';',"��ϲ��õ�������"HIR+item->get_name());
		break;
	case 812:
	case 822:
	case 832:
	case 842:
	case 852:
	case 862:
		if ( flag == 812 )
			cTmp = "��";
		else if ( flag == 822 )
			cTmp = "��";
		else if ( flag == 832 )
			cTmp = "��ӧǹ";
		else if ( flag == 842 )
			cTmp = "�ŷ���";
		else if ( flag == 852 )
			cTmp = "�»�";
		else if ( flag == 862 )
			cTmp = "ʯ��ȭ��";
		send_user(who,"%c%c%w%s",':',3,this_object()->get_char_picid(),sprintf("��������\n    %s�����ͨ����������ڷ������ڳ��ֵ����켶����õ���³�౦ʯ��˵��ĳ�䱦������ࣻ�ɽ���ʯ������ڷ������ڵ�ս������õ���ŷұ��ʯ��ֻҪ���ܷ������ڵ�ǿ������Ϳ����ҵ���\n"ESC"�뿪",cTmp));
		break;
        }

}

int accept_object(object who, object item)
{
	return "/sys/copy/mirror"->accept_object(this_object(),who,item);
}

void do_accept( string arg )
{
	"/sys/copy/mirror"->do_accept(this_object(),this_player(),arg);
}

void do_query( string arg )
{
	"/sys/copy/mirror"->do_query(this_object(),this_player(),arg);
}
