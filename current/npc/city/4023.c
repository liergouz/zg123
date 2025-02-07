
// �Զ����ɣ�/make/npc/make8020
#include <ansi.h>
#include <npc.h>
#include <task.h>

#define INTERIOR_D      "/inh/city/interior"

inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return 0452; }
void do_welcome(string arg);

// ������ʦ��ʶ��
int is_master() { return 1; }

// ������ʦ��ʶ��(���ͷ)
int is_basic_master() { return 2; }

int is_self_look() { return 1; }

// ������С��ʶ��
int is_seller() { return 1; }

// ���������촦��
void create()
{
        set_name("κ������");
        set_real_name("����61~80");
        set_city_name("κ��");
        set_2( "talk", ([
                "welcome"          : (: do_welcome :),
        ])); 
//	set("level",112);
//	set("legend",({32*44+4}));
	set("mpLegend",([110:({32*44+4}),]));
	set("mpLegend2",([110:({32*44+6,32*44+9,32*44+12,}),]));
	set_skill(0630, 39);
        set_2( "good", ([
                "01" : "/item/product/63023",
                "02" : "/item/product/63024",
                "03" : "/item/product/63025",
                "04" : "/item/product/63026",
                "05" : "/item/product/63027",
                "06" : "/item/product/63028",
                "07" : "/item/product/63029",
                "08" : "/item/product/63030",
                "09" : "/item/product/63031",
                "10" : "/item/product/63032",        
                "11" : "/item/product/63033",
                "12" : "/item/product/63034",
                "13" : "/item/product/63035",
                "14" : "/item/product/63036",
                "15" : "/item/product/63037",
                "16" : "/item/product/63038",
                "17" : "/item/product/63039",                                             
        ]) );	
        setup();
}

void do_look( object who )
{
	string tmp="";
	object me = this_object();
	if ( (who->get_level() >= 110 && !who->get_legend(TASK_44,4)) || (who->get_legend(TASK_44,4) && !who->get_legend(TASK_44,6)) )
		tmp += sprintf(ESC HIY "������ľͷ\ntalk %x# welcome.1\n",getoid(me));
	if ( (who->get_legend(TASK_44,6) && !who->get_legend(TASK_44,7)) || (who->get_legend(TASK_44,7) && !who->get_legend(TASK_44,9)) )
		tmp += sprintf(ESC HIY "����\ntalk %x# welcome.1\n",getoid(me));
	if ( (who->get_legend(TASK_44,9) && !who->get_legend(TASK_44,10)) || (who->get_legend(TASK_44,10) && !who->get_legend(TASK_44,12)) )
		tmp += sprintf(ESC HIY "�ƾ�ʯ\ntalk %x# welcome.1\n",getoid(me));

	tmp += sprintf(ESC"ѧϰ�����\nlearn ? %s\n", me->get_char_id());
	tmp += sprintf(ESC"�����������ܵȼ�61-80�����䷽\nlist %s\n", me->get_char_id());
	if ( sizeof(tmp) )
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"/quest/word"->get_country_word(me) + "\n",get_name(),getoid(me)) +
		tmp +
		ESC"�뿪");
	else
		send_user(who,"%c%c%w%s",':',3,get_char_picid(),sprintf( "%s��\n    "+"/quest/word"->get_country_word(me) ,get_name()));
	
}

int accept_object( object who, object obj ) { return INTERIOR_D->accept_object_2( who, this_object(), obj, 8 ); }

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag,i,size,p,amount;
        object who,item, *inv;     
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
		case 1:
			if ( who->get_level() >= 110 && !who->get_legend(TASK_44,4) )
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ҵ�Ů����Ҫ�����ˣ���������ϵ�����ôҲ���ó��������ļ�ױ�ɣ�����Ϊ�Ժ��ľ����ҵ������ˣ�����ƽʱ��̵Ķ����һ��������⣬��һ��Ҫ�ó�ѹ���ӵı���������ʦ��������������һ��ͼֽ������ȵԵ������˵˯��ȥ�ܱ��ӷ��޷��޶�������ù��ӡ���֪��������Ը����Ҵ�������Ը����������Ҫ30����һ�ɣ������磬û�������ĵ�������ľͷ����֪��������û����������㵽����˵���������������ľͷ����������ǰ��������\n"ESC"��������\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
			else if ( who->get_legend(TASK_44,4) && !who->get_legend(TASK_44,5) )
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �Ҳ���������ô��Ī���ҵ���Ը��ȻҪ�����ô����������Ĳ��Ǹ����ϵ���������ױ�����ܸ��ҹ�Ů���á�\n"ESC"�뿪", me->get_name()));
			else if ( who->get_legend(TASK_44,5) && !who->get_legend(TASK_44,6) )
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��Ȼ������ľ�Ĵ�С��һ�㲻�����������ȴ������һ������֮����鷳��\n"ESC"�������\ntalk %x# welcome.3\n"ESC"�뿪", me->get_name(),getoid(me)));
			else if ( who->get_legend(TASK_44,6) && !who->get_legend(TASK_44,7) )
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����������͵��������ǣ��ҵľ��ӿ��Ǵ�ʦŷ����Ϊ�˴�л�Ұ�����ȵԵ�����Զ���ģ��ұ���һ��Ϊ�˵͵����б�Ҳ����¶����ô��������˾�˵�������أ����һ���ȱ������ĶŶ���˵������Ӳ�Ǵ����Ҽ������ˣ��ҵȰ���С�������Ĺ���֪��������ѧ�����߰������յĶŶ���������������ͥ�������������������ܰ������ر���ɣ�С���ڴ˶�л�ˡ��Ŷ����ڰ���ׯ������С�ӣ�����������в��ٱ��ƽʱ����ȡ���ᣬ����û�˹������ı����ʧ�ġ�\n"ESC"��������\ntalk %x# welcome.4\n"ESC"�뿪", me->get_name(),getoid(me)));
			else if ( who->get_legend(TASK_44,7) && !who->get_legend(TASK_44,8) )
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �����ѵ��Ŷ�����è�Ĺ�������㶼����û�а취��\n"ESC"�뿪", me->get_name()));
			else if ( who->get_legend(TASK_44,8) && !who->get_legend(TASK_44,9) )
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��������Ϳ����������������������ܰ��Ҷ�ر����һ��������Ŀ����������ᣬ�͵�˵������������⻤�壬�ñ�������\n"ESC"�������\ntalk %x# welcome.5\n"ESC"�뿪", me->get_name(),getoid(me)));
			else if ( who->get_legend(TASK_44,9) && !who->get_legend(TASK_44,10) )
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    �ٺ٣�Ҫ�ǽ��������������ĵ�Ȼ�����ܷ�����Щ��Ч��Ҫ������ô�ܵ������أ���Ҫ�ڴ��Ͽ��Ϸ�����󷨣����ƾ�ʯ���Ǳ�Ҫ�ķ������壬��˵�Ϲ��������������е�����ħս�������Ļƾ�ʯ����Ȼ˵���ȵ��������õķ�����ô�����޴󣬿����������ҵ�ȵԵ�����Ǵ´����ࡣ��ɸҴ�������Ϊ��ȡ���ƾ�ʯ����Ҫ������ô�̣��Ǻǣ��������գ�ˡ���⴫��Ҫ������ô�����أ�\n"ESC"��������\ntalk %x# welcome.6\n"ESC"�뿪", me->get_name(),getoid(me)));
			else if ( who->get_legend(TASK_44,10) && !who->get_legend(TASK_44,11) )
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n   ������Ȼ���������������Ķ�������Ȼû����ô�����ҵ��������������Ұɡ�\n"ESC"�뿪", me->get_name()));
			else if ( who->get_legend(TASK_44,11) && !who->get_legend(TASK_44,12) )
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ����������������Ҫ�Ķ���Ҳ�����ˣ��ҿ�����һ������һ�����ȵԵ���ĳɾ͸��ˣ�ι������С�ӻ�վ�������߿��߿����ҵĶ��ż��տɲ��ܱ���͵ѧ��ȥ���Ҳ����Ѿ�����Ǯ��ô���������ڴ���������ȥ��ȥ�����������ˣ���ס��ǧ�����͵����Ҫ������϶���������\n"ESC"�������\ntalk %x# welcome.7\n"ESC"�뿪", me->get_name(),getoid(me)));

	        	break; 
	        case 2:
	        	if ( who->get_level() >= 110 && !who->get_legend(TASK_44,4) )
	        	{
	        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
	        		who->set_legend(TASK_44,4);
	        		who->delete_save("wggjmutou");
				send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_WEIGUO,"κ��" );
				send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,62,"Ư���Ĵ���1��" );
				send_user( who, "%c%s", '!', "�õ����� "HIY"Ư���Ĵ���1��");
	        	}
	        	break;         	
		case 3:
	        	if ( who->get_legend(TASK_44,5) && !who->get_legend(TASK_44,6) )
	        	{
	        		if (TASK_LEGEND_D->check_task_item(who,"������ľͷ",30) != 1 )
	        			return;
				TASK_LEGEND_D->task_finish(who);
				who->set_legend(TASK_44,6);
	        		who->delete_save("wggjmutou");
				who->add_exp(50000);
				who->add_potential(700);
				who->add_cash(48000);
				send_user(who,"%c%s",';',"Ư���Ĵ���1�� ���� 50000 Ǳ�� 700 ��Ǯ 48000");
				send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,62,"" );
		      		me->do_welcome(1);
		      	}
	        	break;
	        case 4:
	        	if ( who->get_legend(TASK_44,6) && !who->get_legend(TASK_44,7) )
	        	{
	        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
	        		who->set_legend(TASK_44,7);
				send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_WEIGUO,"κ��" );
				send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,63,"Ư���Ĵ���2��" );
				send_user( who, "%c%s", '!', "�õ����� "HIY"Ư���Ĵ���2��");
	        	}
	        	break;         	
		case 5:
	        	if ( who->get_legend(TASK_44,8) && !who->get_legend(TASK_44,9) )
	        	{
	        		if (TASK_LEGEND_D->check_task_item(who,"�����ľ���",1) != 1 )
	        			return;
				TASK_LEGEND_D->task_finish(who);
				who->set_legend(TASK_44,9);
				who->add_exp(50000);
				who->add_potential(700);
				who->add_cash(48000);
				send_user(who,"%c%s",';',"Ư���Ĵ���2�� ���� 50000 Ǳ�� 700 ��Ǯ 48000");
				send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,63,"" );
		      		me->do_welcome(1);
		      	}
	        	break;
	        case 6:
	        	if ( who->get_legend(TASK_44,9) && !who->get_legend(TASK_44,10) )
	        	{
	        		if ( TASK_LEGEND_D->can_task_add(who) != 1 ) return;
	        		who->set_legend(TASK_44,10);
	        		who->delete_save("wggjhuangjs");
				send_user( who, "%c%c%c%w%s", 0x51, 2, 1,TID_WEIGUO,"κ��" );
				send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,64,"Ư���Ĵ���3��" );
				send_user( who, "%c%s", '!', "�õ����� "HIY"Ư���Ĵ���3��");
	        	}
	        	break;         	
		case 7:
	        	if ( who->get_legend(TASK_44,11) && !who->get_legend(TASK_44,12) )
	        	{
	        		if (TASK_LEGEND_D->check_task_item(who,"Ư���Ļƾ�ʯ",8) != 1 )
	        			return;
	        		TASK_LEGEND_D->give_item(who,"item/product/62092",1);
				TASK_LEGEND_D->task_finish(who);
				who->set_legend(TASK_44,12);
				who->delete_save("wggjhuangjs");
				who->add_exp(180000);
				who->add_potential(1400);
				who->add_cash(190000);
				send_user(who,"%c%s",';',"Ư���Ĵ���3�� ���� 180000 Ǳ�� 1400 ��Ǯ 190000 ͸�궤ͼֽ 1");
				send_user( who, "%c%c%c%w%w%s", 0x51, 2, 2,TID_WEIGUO,64,"" );
		      	}
	        	break;
        }
}