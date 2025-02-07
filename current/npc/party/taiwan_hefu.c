
#include <npc.h>
#include <ansi.h>
#include <task.h>

inherit OFFICER;

// ��������ȡ��������
int get_char_picid() { return 9957; }
void do_welcome(string arg);

// ���������촦��
void create()
{
        set_name("�Ϸ�����ʹ��");

	set_2( "talk", ([
                "welcome"        : (: do_welcome :),
        ]));

        setup();
}

void do_look( object who )
{
	object me = this_object();
	string tmp = sprintf(ESC"��ȡ����\ntalk %x# welcome.1\n",getoid(me));
	send_user(who,"%c%s",':',sprintf( "%s��\n    ��Ϊ�Ϸ��Ĺ�ϵ�������ص�Ϊ��������˲�����ֻҪ�ȼ�������"HIR "60��"NOR"����Ҷ���������������ȡһ�������"HIR"3��23����28��"NOR"�Ҷ����������ҿ�ǧ��Ҫ�����λ��ᡣ\n", get_name()) + tmp + ESC"�뿪");
}

void do_welcome( string arg )
{
        object me = this_object();
        __FILE__ ->do_welcome2(me, arg);
}

void do_welcome2( object me, string arg )
{
        int flag,i,size,p;
        object who,item;     
	string name1;
	string *giftname = ({ "0104", "0109", "0111", "0121", "0131", "0141", "0151", "0161", "0202", "0401", "0402", "0403", "0211", "0212", "0316", "0317", "0319", "0221", "0231", "0222", "0325", "0329", "0241", "0251", "0242", "0348", "0349", "0261", "0363", "0364", "0365", "0368", "0271", "0413", "0414", "0417", "0418", "0421", "0422", "0423", "0424", "0425", "0281", "0501", "0511", "0531", "0591", });
	string *file = ({"0006","0007","0009","0012",});
        who = this_player();
        flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
        	if ( who->get_level() >= 60 && who->get_save_2("receive.prize") != 1 )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ������һ��СС�����⣬���°ɡ�ϣ���ܸ�����Щ������\n"ESC"���ܽ�Ʒ\ntalk %x# welcome.2\n"ESC"�뿪", me->get_name(),getoid(me)));
        	else if ( who->get_save_2("receive.prize") == 1 )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��֮ǰ�����Ѿ���ȡ����Ʒ������ô���������ˣ�̰�Ŀɲ���һ�������顣\n"ESC"�뿪", me->get_name()));
		else if ( who->get_level() < 60 )
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n    ��ĵȼ�������"HIR "60��"NOR"�ɣ�ʮ�ֱ�Ǹ�Ҳ����������������㡣�ú�Ŭ���ɣ���"HIR"3��23����28��"NOR"�Ҷ���������ġ�\n"ESC"�뿪", me->get_name()));
        	break;
	case 2:
        	if ( who->get_level() >= 60 && who->get_save_2("receive.prize") != 1 )
        	{
			if(USER_INVENTORY_D->count_empty_carry(who) < 7 )
			{
			        send_user(who,"%c%s",';',"�����ϵĵ��߿ռ䲻̫�㹻���ڳ�7����λ�ú������ɡ�");
        			return;
			}

			size = sizeof(giftname);
			name1 = giftname[random(size)];
			item = new (sprintf("/item/95/%s.c", name1));
			p =item->move(who, -1);
			item->add_to_user(p);

        		item = new("/item/sell/0002");
        		p = item->move(who,-1);
        		item->add_to_user(p);

        		item = new("/item/sell/0004");
        		p = item->move(who,-1);
        		item->add_to_user(p);

                        for (i=0;i<4;i++)
                        {
				item = new (sprintf("/item/sell/%s.c", file[i]));    
				item->set_amount(5);
                        	if ( item )
				{	
					p = item->move(who,-1);
					item->add_to_user(p);			
				}	
			}
        		who->set_save_2("receive.prize",1);
        	}
        	break;  
        }
}