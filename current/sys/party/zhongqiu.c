/*****
���±�������
****/

#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <public.h>
#include <time.h>
#include <action.h>
#include <skill.h>

#define YUEBING	"item/04/0408"
#define YUTU	"npc/party/0009"

int iStart,iFinish;
object change,change1;
int *nScene = ({1,10,20,30,40,50,60,70});
string *nWord = ({
	"����Բ�������������ң������´����ҵ���Ը��ף����ף��������֣���Բ��Բ����Բ��",
	"����~�뵽~�ĵ���˵��~����~�õ���ʱ�䵽���ҵ�����ף����˼���Ѿ�ȫ�����յ���",
	"�ҵ����ڼ����ϣ�������������û������ϵ��£����������������������ҹ���ҽ����º������ų�������ף����������֡�",
	"������Ŀ���������������·�����һ�������������ڻ���ע������˼���ף����",
	"�ҽ����ID���������һ��İ���ˣ��������ϣ�������������ԲҹҪ���Ҹ����㣬��˼���㡣",
	"Զ�����������Ƿ����������˼��ļ�����ı���ҵ����գ��������Զ��ǣ������ģ�",
	"��ȱʱ�����㣬��Բʱ�����㣬������Բ��ȱ���ҵ������Ǻ�Ų��������ĬĬ׷����ף���㡣",
	"�±��ڵ��ˣ��꣡��֨����������Ļ��һ�£�����һ�£��Ǻǣ��ҿ����ˣ����ˣ�Ը����֣�",
	"һ����˼һ�ź춹����Բʱ���һ���������ȥ�����Ƶ��±���������֣�",
	"���������£����Ĺ���ʱ��",
	"�����������£�������Զ�����㣻��ԡ�»Ե���ܰ���͸��ܵ��������Ц�ݡ��װ��ģ������㡣 ",
	"����ѽڣ�ԶԶ�����ԲԲ�ı���ԲԲ������ԲԲ���£���Ҫ����Զ�����ң� ",
	"��Բԣ�Ұãã���и��˶���Զ������紵�������㡣����ɷ�ع��磿 ",
	"���±��޼ۣ���ɽ�����顣Ը������������ʮ�������һ����ԲԲ����������������±�����ͬһ��ף������",
	"��Ե����Ե����Բ������֮ҹ����˼��������Բ����Բ����ȥ�ʺ��˼���������³�ԸԵԲ��",
	"��˼��һ��ŨŨ�ľƣ����ھٱ�ʱɢ�������˵ķҷ��������һ�ݺ����飬������Բʱ�ỽ�����Ե���ꡣ",
	"һ������һ���㣬����Ӱ���Һ��㣬����������ʶ�㣬�ĸ����������㣬����ĺ�Ѱ���㣬�������������㣬���ǰ���Χ���㣬����ʮ���ҵ��㡣",
	"�����±������ڣ����������ܼ��棻���Ƿ��������ߣ�׷׷�������ǣ��������������Ȫ����������һ���꣡",
	"ÿ��ѽڱ�˼�ף����Ҹ����ƺ����Բ��������ʱ���������ܲ�˼����",
	"���ǻ�����ʣ��Ҵ������Ը���˻�������ʯ���Ҵ����ף�������½���һ�飬�Ҵ��������������ֻ��һ�أ�������û�д����������ѣ��������㹲ͬ���£� ",
	"��Խ��Խ���������ཻԽ��Խ�棻ˮԽ��Խ�壬�����ɣԽ��Խ����ף��������ѽڹ��ÿ��ģ� ",
	"ȥ��Բ��ʱ�����������磻��������ͷ����Լ�ƻ�󡣽���Բ��ʱ����������ɣ�����ȥ���ˣ���ʪ�����䡣",
	"������˼����ŨŨ�������˶������ڻ������ǹ���������������á�",
	"�����ȥ���ҵ�ף�������´������ҵ��ʺ����Ǽ��������յĹ��£���������������ļ��顣ף������ѽڿ��֣���Բ��Բ����Բ����",
	"�˸�ǧ�·���ƣ�ȴ��Ҫ�ʡ�����ƾ�������´���Ѷ������Ƭֽ��ο���顣",
	"¶�ӽ�ҹ�ף����ǹ���������ҹ����Բ������˼��ʱ��ͬ�������£���Բ��δԲ��",
	});

void generate_yutu();
void destroy_yutu();
void destroy_yuebing();
void generate_yuebing();
int check_yuebing(object who, int count);
int give_yuebing(object who, int count);
int exchange( object who,object me,object yuebing);
void yutu_message();
void yuebing_message();

// ���������ɶ�������
void SAVE_BINARY() { }

void create()
{
	iStart = mktime(2006,10,10,0,0,0);	
	iFinish = mktime(2006,10,18,0,0,0);	
	call_out("check_time",1);
}

void check_time()
{
	int iHour;
	mixed *mixTime;

	remove_call_out("check_time");
	if ( "sys/main/main"->get_host_type() != 2 )
		return ;
	iHour = time();
	if ( iHour > iFinish )
		return ;
	if ( iHour < iStart )
	{
		call_out("check_time",3600*6);
		return ;
	}
	if ( !objectp(change) )
	{
		change = new("npc/party/0008");
		change->add_to_scene(80,294,191);
	}
	if ( !objectp(change1) )
	{
		change1 = new("npc/party/0008");
		change1->add_to_scene(1,205,170,4);
	}
	mixTime = localtime(time());
	iHour = mixTime[TIME_HOUR];
	
	call_out("check_time",60*(60-mixTime[TIME_MIN]));
	if ( YUTU->get("dates") != mixTime[TIME_YDAY] )
	{
		YUTU->delete("send_yutu");
		YUTU->delete("send_yb");
		YUTU->set("dates",mixTime[TIME_YDAY]);	
	}
	if ( iHour == 9 || iHour == 14 || iHour == 18 || iHour == 21 )	//Ԥ������
	{
		if ( mixTime[TIME_MIN] >= 55 )
		{
			yutu_message();
		}
		else
		{
			remove_call_out("yutu_message");
			call_out("yutu_message",60*(55-mixTime[TIME_MIN]));
		}	
	}
	if ( iHour%2 )	//Ԥ���±�
	{
		if ( mixTime[TIME_MIN] >= 55 )
		{
			yuebing_message();
		}
		else
		{
			remove_call_out("yuebing_message");
			call_out("yuebing_message",60*(55-mixTime[TIME_MIN]));
		}		
	}
//	if ( iHour == 9 || iHour == 15 || iHour == 16 || iHour == 20 || iHour == 23 )	//Ԥ��˫��
//		CHAT_D->sys_channel(0,HIY"Ϊ��л��ҶԴ�ս��online��֧�֣����ڹ�����������֮�ʣ�ÿ�����������1��Сʱ��˫�����飬�����ȥ����̳�����ִ���϶���ȡ��");
		
	if ( iHour == 10 || iHour == 15 || iHour == 19 || iHour == 22 )	//ˢ������
	{
		if ( YUTU->get("send_yutu") != iHour )
		{
			generate_yutu();
			YUTU->set("send_yutu",iHour);
		}
	}
	else if ( iHour == 12 || iHour == 17 || iHour == 21 || iHour == 0 )
	{
		destroy_yutu();
	}
	if ( !(iHour%2) && (YUTU->get("send_yb") != iHour+1) )	//ˢ���±�
	{
		destroy_yuebing();
		generate_yuebing();		
		YUTU->set("send_yb",iHour+1);
	}
	
}

void generate_yutu()
{
	int i,size,z,p,x,y;
	object *nObj,npc;
	
	nObj = ({});
	for(z=10;z<=70;z+=10)
	{
		for(i=0;i<50;i++)
		{
			if( !( p = efun::get_xy_point( z, IS_CHAR_BLOCK ) ) )
				continue;
			x = ( p % 1000000 ) / 1000;  y = p % 1000;
			npc = new(YUTU);
			if ( !objectp(npc) )
				continue;
			npc->add_to_scene(z,x,y);	
			nObj += ({ npc });
//			log_file("zhongqiu.txt",sprintf("%s %d %d %d %d\n",short_time(),i,z,x,y));	
		}
	}
	log_file("zhongqiu.txt",short_time() + " ������\n" );
	YUTU->set("npc",nObj);
	CHAT_D->sys_channel(0,HIR"�϶����ӵ�������Ϊ̰���ܵ����䣬��������Ұ��Ⱥ�����·Ӣ���ڹ��ҳ����æѰ�ؽ����϶����ӡ�");
}

void destroy_yutu()
{
	int i,size,z,p,x,y;
	object *nObj,npc;

	nObj = 	YUTU->get("npc");
	for(i=0,size=sizeof(nObj);i<size;i++)
	{
		if ( !objectp(nObj[i])	)
			continue;
		nObj[i]->remove_from_scene();
		destruct(nObj[i]);
	}
	YUTU->delete("npc");
}

void before_destruct()
{
	if ( objectp(change) )
	{
		change->remove_from_scene();
		destruct(change);
	}
	if ( objectp(change1) )
	{
		change1->remove_from_scene();
		destruct(change1);
	}
}



void generate_yuebing()
{
	int i,size,z,p,x,y,j,count;
	object *nObj,item;
	
	destroy_yuebing();
	nObj = ({});
	for(j=0,count=sizeof(nScene);j<count;j++)
	{
		z = nScene[j];
		for(i=0;i<80;i++)
		{
			if( !( p = efun::get_xy_point( z, IS_CHAR_BLOCK ) ) )
				continue;
			x = ( p % 1000000 ) / 1000;  y = p % 1000;
			item = new(YUEBING);
			if ( !objectp(item) )
				continue;
			item->add_to_scene(z,x,y);	
			nObj += ({ item });
//			log_file("zhongqiu.txt",sprintf("%s %d %d %d %d\n",short_time(),i,z,x,y));	
		}
	}
	log_file("zhongqiu.txt",short_time() + " ���±�\n" );
	YUTU->set("item",nObj);
	CHAT_D->rumor_channel(0,HIR"�϶����±�������ҿ�ȥ������");
}

void destroy_yuebing()
{
	int i,size;
	object *nObj;	
	nObj = YUTU->get("item");
	for(i=0,size=sizeof(nObj);i<size;i++)
	{
		if ( !objectp(nObj[i]) )
			continue;
		nObj[i]->remove_from_scene();
		destruct(nObj[i]);
	}
	YUTU->delete("item");
}

//��ץ����
void get_yutu(object me, object who)
{
	int iExp;
	object item;
	
	if ( !who->is_yutu() )
	{
                send_user(me, "%c%s", '!', "���ܲ�ץ�Է���");
                return ;        	
        }
	if (distance_between(me, who)>7)
        {
                send_user(me, "%c%s", '!', "������Ŀ��̫Զ��");
                return ;        	
        }
        if( !objectp( item = present("Ǭ����", me, 1, MAX_CARRY) ) )
        {
                send_user(me, "%c%s", '!', "������Ǭ�������ܲ�ץ��");
                return ;
        }
	if ( me->get_save("tanciyutu") )
	{
                send_user(me, "%c%s", '!', "���Ѿ����϶��ҵ������ˣ�Ϊʲô�������أ�");
                return ;        	
        }
	item->add_amount(-1);     	
	if ( random(100) < 90 )
	{
                send_user(me, "%c%s", '!', "��ץʧ�ܣ�");
                return ;        	
        }
        if ( random(100) < 90 )
        {
        	iExp = me->get_level() * 20 ;
        	me->add_exp(iExp);
                send_user(me, "%c%s", ';', sprintf("�ܿ�ϧ������׽�����Ӳ������϶�����ã��������ǻ�õ�%d����Ľ���Ŷ��",iExp));
        }
        else
        {
                send_user(me, "%c%s", ';', "���ɹ������϶�Ѱ�����ã��Ͽ�ȥ�ܹ���̳�������϶�ɣ�˵�����д���������أ�");
        	me->set_save("tanciyutu",1);
        }
	who->remove_from_scene(FALL_ACT);
	destruct(who);
}

void do_look(object me,object who)
{
	int id = getoid(me),i;
	i = time();
//	if ( i >iStart && i < iFinish )
//		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �϶�����ף�������������֣������³ɣ�\n"ESC"��������\ntalk %x# welcome.1\n"ESC"�±��һ�\ntalk %x# welcome.3\n"ESC"��ȡ˫������ʱ��\ntalk %x# welcome.8\n"ESC"�뿪",me->get_name(),id,id,id));
//	else
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �϶�����ף�������������֣������³ɣ�\n"ESC"��������\ntalk %x# welcome.1\n"ESC"�±��һ�\ntalk %x# welcome.3\n"ESC"�뿪",me->get_name(),id,id,id));
		
}

void do_welcome( object me, string arg )
{
	int flag,i;
	int id = getoid(me);
       	object who,item,player;  
       	string name,cTmp,id1; 
	mixed *mixTime;
        who = this_player();
        if ( sscanf(arg,"%d.%s",flag,id1) != 2 )
        	flag = to_int(arg);
        who->set_time( "talk",  0);
        switch(flag)
        {
        case 1:
		if ( who->get_save("tanciyutu") )
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ����ڵ��ˣ���������Ϊ̰�Է�����±�����Ȼ˽���·��������߹����⣨���ܹ�����Ұ��Ⱥ�У�������лл�������һ������ã���������������͸����ˣ�\n"ESC"��ȡ����\ntalk %x# welcome.2\n"ESC"�뿪",me->get_name(),id));
		else
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����Ӳ�֪������͵�±���ȥ�ˣ���ȥ�߹����⣨���ܹ����ú����Ұɣ��������һ�������һ������һ�ݴ���\n"ESC"�뿪",me->get_name()));
        	break;
        case 2:
		if ( who->get_save("tanciyutu") )
		{
			i = random(100);
			if ( i < 10 )	//������
			{
				item = new("item/final/16/1636");
				cTmp = "һֻ"HIR"�ɰ���������";	
			}	
			else if ( i < 35 )	//����
			{
				item = new("item/04/0407");	
				cTmp = "һ��"HIR"����";	
			}
			else			//����ڴ����
			{
				item = new("item/04/0406");	
			}
			if ( !objectp(item) )
				return ;
			i = item->move(who,-1);
			if ( !i )
			{
				send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϲ����ռ�����͸���������������������������Ŷ��\n"ESC"�뿪",me->get_name()));
				return ;
			}
			item->add_to_user(i);
                	send_user(who, "%c%s", ';', "��ϲ�������õ����϶����͵�����������"HIG+item->get_name());
        		if ( cTmp )
        			CHAT_D->sys_channel(0,sprintf("��ϲ%s�����%s",who->get_name(),cTmp));
			who->delete_save("tanciyutu");
		}
		break;
        case 3:
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ����ѽڱ�˼�ס�������ر�Ľ�������Ƿ�Ҳ��˼����ˣ����Ƿ��кܶ໰�����˼�����˵���ǸϽ�ȥ�Ѽ��±��ɣ����������ʵ��Ը����Ŷ��\n"ESC"����3���±������ѷ�����ܰ��ף��\ntalk %x# welcome.4\n"ESC"����1���±��һ���������\ntalk %x# welcome.5\n"ESC"�뿪",me->get_name(),id,id));
        	break;
        case 4:
        	if ( check_yuebing(who,3) == 0 )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵ��±����񲻶��S����㽨���㵽�������ҵĳ������ߣ�˵����������ľ�ϲ�ء�\n"ESC"�뿪",me->get_name()));
			return ;        			
        	}
		send_user( who, "%c%c%d%s", '?', 16, 30, "�ڿ������������ѵ�ID�����������������ѷ���ף�������������0�Ļ����Ϳ�����ȫ����������ҷ���ף����\n"+sprintf( ESC"talk %x# welcome.6",getoid(me))+".%s\n");		
        	break;
        case 5:
        	if( !objectp( item = present("�±�", who, 1, MAX_CARRY) ) || item->is_zhongqiu() != 1 )
	       	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵ��±����񲻶��S����㽨���㵽�������ҵĳ������ߣ�˵����������ľ�ϲ�ء�\n"ESC"�뿪",me->get_name()));
			return ;        			
        	}
        	exchange(who,me,item);
        	break;
        case 6:
        	if ( !sizeof(id1) )
        		return ;
        	cTmp = nWord[random(sizeof(nWord))];
        	if ( id1 == "0" )
        		name = "���";
		else
		{        
			i = to_int(id1);
			if ( !i )
				return ;		
        		player = find_char(id1);
			if ( !objectp(player) )
			{
        			if( !( who->get_friend_id(i) ) )
        			{
					send_user(who,"%c%s",'!',"����Ҳ����߲��Ҳ��ں����б����ܷ���ף����");
					return ;
				}
				name = who->get_friend_name(i);
			}
			else
				name = player->get_name();
			MAILBOX->send_mail(who,i,cTmp);			
		}
		if ( give_yuebing(who,3) == 0 )
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵ��±����񲻶��S����㽨���㵽�������ҵĳ������ߣ�˵����������ľ�ϲ�ء�\n"ESC"�뿪",me->get_name()));
			return ;        			
        	}
        	cTmp = sprintf("%s��%s˵��%s",who->get_name(),name,cTmp); 		
        	CHAT_D->sys_channel(0,HIR+cTmp);
		send_user( CHAT_D->get_chat(), "%c%s", 0xA3, HIY+cTmp );
		if ( random(1000)>4 )
			return ;
		item = new("item/04/0405");
		i = item->move(who,-1);
		if ( !i )
		{
			destruct(item);
			return ;
		}
		item->add_to_user(i);
		send_user(who,"%c%s",'!',"��ϲ�㣬�õ��˽�Ʒ�����");
        	break;
        case 7:
        	return ;
        	if ( time() < iStart )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��û����˫��ʱ�䡣ף����Ϸ��죡\n"ESC"�뿪",me->get_name()));
        		return ;	
        	}
		if ( time() > iFinish )
		{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �������˫��Ѿ������ˡ�ף����Ϸ��죡\n"ESC"�뿪",me->get_name()));
        		return ;	
        	}
		mixTime = localtime(time());

		if ( who->get_save("changer930") == mixTime[TIME_YDAY])
        	{
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����첻���Ѿ����һ���������������ɡ�\n"ESC"�뿪",me->get_name()));
        		return ;	
        	}
        	i = gone_time( who->get_login_time() );
		if ( i+ who->get_game_time()<who->get_double_time())
		{
		        send_user( who, "%c%c%w%s", ':', 3, me->get_char_picid(),
		        	sprintf("%s��\n     ����˫������ʱ�仹ʣ %d �룬������ȡ\n"
		                ESC "�ر�\nCLOSE\n", me->get_name(), who->get_double_time() - i - who->get_game_time() ) );			
			return;		               
		}
        	who->set_save("changer930",mixTime[TIME_YDAY]);
		who->set_double_time(i+ who->get_game_time()+3600);        	
		send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ���ɹ���ȡ��һСʱ˫�����飬��Ҫ�ú�����Ŷ��\n"ESC"�뿪",me->get_name()));
		send_user( who, "%c%c%c%w%s", 0x51, 1, 1,0001,"��Ϸ����" ); 
		send_user( who, "%c%c%c%w%w%s", 0x51, 1, 2, 0001, 1, "˫��ʱ��" ); 

        	break;	 
        case 8:
        	return ;
        	send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    ��ȷ��Ҫ��ȡ˫������ʱ����\n"ESC"ȷ��\ntalk %x# welcome.7\n"ESC"�뿪",me->get_name(),getoid(me)));
		break;
        }

        
}


int exchange( object who,object me,object yuebing) 
{
	int rate,p,cash,exp,pot;
	object item;
	string name;
	
	rate = random(10000);
	if ( rate < 3000 )
	{
		exp = 400;
	}
	else if ( rate < 6000 )
	{
		pot = 30;
	}
	else if ( rate < 6010 )		//ս����
	{
		item = new("item/08/0001");
		name = "ս����";
	}
	else if ( rate < 6035 )	//ս���Ž�
	{
		item = new("item/08/0002");
		name = "ս���Ž�";
	}
	else if ( rate < 6055 )	//Ѫʯ
	{
		item = new("item/08/0003");
	}
	else if ( rate < 6080 )	//����ʯ
	{
		item = new("item/08/0004");
	}
	else if ( rate < 6105 )	//���ܽ�����
	{
		item = new(BOOK_FILE->get_book_file());
		name = item->get_name();
	}
	else if ( rate < 9180 )
	{
		cash = 1000;
	}
	else if ( rate < 9185 )	//�ٱ���
	{
		item = new("item/std/6001");
		name = "�ٱ���";
	}
	else if ( rate < 9200 )	//������
	{
		item = new("item/91/9178");
		name = "������";
	}
	else if ( rate < 9500 )	//������Ʒ
	{
		p = random(6);
		switch(p)
		{
		default:	
			item = new("item/final/91/1808");
			break;
		case 1:	
			item = new("item/final/91/1809");
			break;
		case 2:	
			item = new("item/final/91/1810");
			break;
		case 3:	
			item = new("item/final/91/1811");
			break;
		case 4:	
			item = new("item/std/5211");
			item->set_amount(3);
			break;
		case 5:	
			item = new("item/91/9145");
			item->set_amount(2);
			break;										
		}
	}
	else if ( rate < 9800 )	//��ʳ��Ʒ
	{
		p = random(5);
		switch(p)
		{
		default:	
			item = new("item/final/33/1706");
			break;
		case 1:	
			item = new("item/final/33/1707");
			break;
		case 2:	
			item = new("item/final/33/1708");
			break;
		case 3:	
			item = new("item/final/33/1753");
			break;
		case 4:	
			item = new("item/final/33/1755");
			break;
		}
		item->set_amount(2);
	}
	else			//�����г�Ʒ
	{
		p = random(4);
		switch(p)
		{
		default:	
			item = new("item/final/16/1607");
			break;
		case 1:	
			item = new("item/final/16/1612");
			break;
		case 2:	
			item = new("item/final/16/1609");
			break;
		case 3:	
			item = new("item/final/16/1610");
			break;
		}
	}
	yuebing->add_amount(-1);
	if ( item )
	{
		p = item->move(who,-1);
		if ( !p ) 
		{
			destruct(item);
			if ( objectp(yuebing) )
				yuebing->add_amount(1);
			send_user(who,"%c%c%w%s",':',3,me->get_char_picid(),sprintf("%s��\n    �����ϵĶ�������̫���ˣ�����һ�������һ�����ɡ�\n"ESC"�뿪",me->get_name()));
			return 0;	
		}
		send_user(who,"%c%s",'!',"��ϲ�������õ���"+item->get_name());
		item->add_to_user(p);	
		if ( name )
        		CHAT_D->sys_channel(0,sprintf("��ϲ%s�������±�������"HIR"%s",who->get_name(),name));
	}
	else if (  cash )
	{
		who->add_cash(cash);
		send_user(who,"%c%s",'!',sprintf("��ϲ�������õ���%d��",cash));
	}
	else if (  pot )
	{
		who->add_potential(pot);
		send_user(who,"%c%s",'!',sprintf("��ϲ�������õ���%d��Ǳ��",pot));
	}
	else if (  exp )
	{
		who->add_exp(exp);
		send_user(who,"%c%s",'!',sprintf("��ϲ�������õ���%d�㾭��",exp));
	}
	return 1;
}

int check_yuebing(object who, int count)
{
	int i,size,amount;
	object *inv,item;	
	string name="�±�";
	inv = all_inventory(who, 1, MAX_CARRY);
	
	if( !objectp( item = present(name, who, 1, MAX_CARRY) ) || item->is_zhongqiu() != 1 )
	{
		return 0;	
	}			
	for(i=0,size=sizeof(inv);i<size;i++)
	{
		if ( !objectp(inv[i]) )
			continue;
		if ( inv[i]->get_name() != name || inv[i]->is_zhongqiu() != 1 )
			continue;
		if ( inv[i]->is_combined() )
			amount += inv[i]->get_amount();		
		else
			amount ++;
	}
	if ( amount < count )
	{
		return 0;	
	}
	return 1;
}

int give_yuebing(object who, int count)
{
	int i,size,amount;
	object *inv,item;	
	string name="�±�";
	if ( check_yuebing(who,count) != 1 )
		return 0;
	inv = all_inventory(who, 1, MAX_CARRY);
	for(i=0,size=sizeof(inv);i<size;i++)
	{
		if ( !objectp(inv[i]) )
			continue;
		if ( inv[i]->get_name() != name || inv[i]->is_zhongqiu() != 1 )
			continue;
		amount = inv[i]->get_amount();
		if ( count >= amount )
		{
			inv[i]->remove_from_user();
			destruct(inv[i]);
			count -= amount;
		}
		else
		{
			inv[i]->add_amount(-count);
			count = 0;	
		}
		if ( count <= 0 )
			break;
	}
	return 1;		
	
}

void yutu_message()
{
	log_file("zhongqiu.txt",short_time() + " Ԥ�������\n" );
	CHAT_D->sys_channel(0,HIR"�϶��������Ϊ̰�Է�����±����Ѿ����¹������ܣ����Ʋ��ú��ᵽ�ﷲ�䣬���·Ӣ���ڸ��������æѰ�����á�");
}

void yuebing_message()
{
	log_file("zhongqiu.txt",short_time() + " Ԥ����±�\n" );
	CHAT_D->sys_channel(0,HIR"�϶���5���Ӻ󼴽���ս������������ִ���Բ���±�����ҿ��׼��Ѱ�Ұɡ��϶�ף��ҽ��տ��֡�");
}