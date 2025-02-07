
#include <ansi.h>
#include <task.h>
#include <time.h>
#include <city.h>

inherit DBASE_F;
inherit SAVE_F;

#define _TEST_WS

#define ENTER_WUSHUANG(x)	x->add_to_scene(701,121,141);
#define GET_TIME	get_party_time()
#define START_ATT_HOUR	19
#define START_ATT_MIN	30
#define FINISH_ATT_HOUR	21
#define FINISH_ATT_MIN	0

int iFlag;		//0 Ϊ�ر�
int iWarStatus;
void org_title(string cName,int flag);
int check_war_time();
string get_occupy_org()	;

// ���������ɶ�������
void SAVE_BINARY() { }

string get_save_file()	{ return "data/wushuang"SAVE_EXTENSION;}

void create()
{
	object npc;
	
	restore();
	call_out("check_time",3);

}

int check_join_attack(object me, object who)
{
	int date;
	mixed *mxTime;
	
	if ( iFlag == 1 )
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ������û������\n"ESC"�뿪",me->get_name()));
		return 0;	
	}
	if ( who->get_org_position() != ORG_MASTER )
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ֻ�а��������ʸ����빥ռ��˫�ǣ�\n"ESC"�뿪",me->get_name()));
		return 0;	
	}
	mxTime = localtime(GET_TIME);
	date = mxTime[TIME_YEAR]*10000+ (mxTime[TIME_MON]+1)*100 + mxTime[TIME_MDAY];
	if ( get_save_2("join_org."+who->get_org_name()+".date") >= date )
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ��İ����Ѿ�����μӹ����ˣ������ظ�������\n"ESC"�뿪",me->get_name()));
		return 0;	
	}
	if ( who->get_cash() < 1000000 )
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ����Я���Ľ�Ǯ������֧�����Ƿ��ã�\n"ESC"�뿪",me->get_name()));
		return 0;	
	}	
		
	return 1;	
}
void query_join_attack(object me, object who)
{
	
	if ( check_join_attack(me,who) != 1 )
		return ;
	send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ��˫������ʵ���͵�λ�����������빥ռ��˫�ǣ��õ����������ϵ���ҫ�������Ƚ���1000000���������ã�\n"ESC"���빥��\ntalk %x# welcome.75\n"ESC"�뿪",me->get_name(),getoid(me)));
	
}

void join_attack(object me, object who)
{
	int date;
	string *nTmp;
	mixed *mxTime;
	
	if ( check_join_attack(me,who) != 1 )
		return ;
	who->add_cash(-1000000);
	mxTime = localtime(GET_TIME+200);
	date = mxTime[TIME_YEAR]*10000+ (mxTime[TIME_MON]+1)*100 + mxTime[TIME_MDAY];
	nTmp = get_save_2(sprintf("attack_list.%d.orgs",date));
	if ( !arrayp(nTmp) )
		nTmp = ({ who->get_org_name() });
	else
		nTmp += ({ who->get_org_name() });
	set_save_2(sprintf("attack_list.%d.orgs",date),nTmp);
	set_save_2("join_org."+who->get_org_name()+".date",date);
	save();
	//���ʼ�������
	"sys/sys/manager"->org_mail(0,who->get_org_name(),sprintf("    ���ｫ��%d��%d��%02d��%02d��%02d��%02d������˫�ǣ����λ��Ա��ʱ���ù���׼����",mxTime[TIME_MON]+1,mxTime[TIME_MDAY],START_ATT_HOUR,START_ATT_MIN,FINISH_ATT_HOUR,FINISH_ATT_MIN));
	send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ���Ѿ��ɹ����빥����˫�ǣ�����ʱ��Ϊ����19.30-21.00����Ҳ����ǰȥ�ܹ�����˫��������270��187�������ѯ��\n"ESC"�뿪",me->get_name()));
	
}
//������˫��
void trans_into_wushuang(object me,object who)
{
	int p,x,y;
	
	if ( iFlag == 1 )
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ������û������\n"ESC"�뿪",me->get_name()));
		return 0;	
	}
	if( !(p = get_jumpin(888, 1)) )
		return ;
	who->add_to_scene(888,p/1000,p%1000);
                                        
}
//�����б�
void attack_list(object me,object who)
{
	int i,j,size,date;
	mixed *mxTime;
	string cTmp;
	string *nTmp;
	
	cTmp = "";
	if ( iFlag == 1 )
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ������û������\n"ESC"�뿪",me->get_name()));
		return 0;	
	}
	for(j=0;j<3;j++)
	{
		mxTime = localtime(GET_TIME + 3600*24*j);
		date = mxTime[TIME_YEAR]*10000+ (mxTime[TIME_MON]+1)*100 + mxTime[TIME_MDAY];	
		nTmp = get_save_2(sprintf("attack_list.%d.orgs",date));
		if ( !arrayp(nTmp) || !(size=sizeof(nTmp)) )
			continue;
		cTmp += sprintf("    %2d��%2d��: ",mxTime[TIME_MON]+1,mxTime[TIME_MDAY]);
		for(i=0;i<size;i++)
		{
			cTmp += nTmp[i] + "��ᡢ";	
		}
		cTmp += "\n";
	}
	if ( sizeof(cTmp) == 0 )
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    Ŀǰ��û�����빥�ǵİ��ɡ�\n"ESC"�뿪",me->get_name()));
		return ;	
	}
	send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ���ڹ��ǰ����:\n%s\n"ESC"�뿪",me->get_name(),cTmp));
}
//ռ�����
void occupy_city(object me, object who)
{
	int date,date1,flag,i,size;
	string org_name,old_org;
	mixed *mxTime;
	object map,*nPlayer,oPlayer;
	
	if ( iFlag == 1 )
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ������û������\n"ESC"�뿪",me->get_name()));
		return ;	
	}
	if ( gone_time(me->get("occupy_time")) < 5 )	//��������ļ��
		return ;
	me->set("occupy_time",GET_TIME);
	map = get_map_object(get_z(me));
	if ( !map || !map->is_wushuang() )
		return ;
	if ( who->get_org_position() != ORG_MASTER )
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ֻ�а����ſ�����ռ����˫�ǣ�\n"ESC"�뿪",me->get_name()));
		return ;	
	}
	if ( get_save_2("occupy_org") == (org_name=who->get_org_name()) )
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ��İ����Ѿ�ռ����˫�ǣ������ٴ�ռ�죡\n"ESC"�뿪",me->get_name()));
		return ;	
	}	
	mxTime = localtime(GET_TIME);
	date = mxTime[TIME_YEAR]*10000+ (mxTime[TIME_MON]+1)*100 + mxTime[TIME_MDAY];
	if ( !get_save_2("old_occupy_org") || get_save_2("old_occupy_org") != org_name )
	{
		if ( (date1=get_save_2("join_org."+org_name+".date")) < date )
		{
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ��İ���û�����빥�ǣ�����ռ�죡\n"ESC"�뿪",me->get_name()));
			return ;	
		}
		if ( date1 > date )
		{
			send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ��İ���û��������չ�����˫�ǣ�\n"ESC"�뿪",me->get_name()));
			return ;	
		}
	}
	if ( check_war_time() != 1 )
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    �����Ƿǹ���ʱ�䣬������Ч��\n"ESC"�뿪",me->get_name()));
		return ;	
	}
	nPlayer = map->get_all_user();
	size = sizeof(nPlayer);
	if ( !size )
		return ;
	for(i=0;i<size;i++)
	{
		oPlayer = nPlayer[i];
		if ( oPlayer && oPlayer->get_org_name() == org_name )
			continue;
		if ( oPlayer->is_die() )
			continue;
		flag = -1;			
		break;	
	}
	if ( flag == -1 )
	{
		send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ��˫���ڻ������������ң����벻����׼��\n"ESC"�뿪",me->get_name()));
		return ;	
	}
	old_org = get_save_2("occupy_org");
	set_save_2("occupy_org",org_name);	
	set_save_2("occupy_time",GET_TIME);
	log_file("wushuang.txt",sprintf("%s %s(%d) %s ռ����˫��\n",
		short_time(GET_TIME),who->get_name(),who->get_number(),org_name));
	save();
	org_title(org_name,1);
	org_title(old_org,0);
	send_user( who, "%c%c%w%s", ':',3,me->get_char_picid(), sprintf("%s:\n    ����ѳɹ�ռ����˫�ǣ��������ǡ���˫��������\n"ESC"�뿪",me->get_name()));
	CHAT_D->sys_channel(0,sprintf(HIY"%s"NOR"�����"HIY"%s"NOR"����ѳɹ�ռ����˫�ǣ�",who->get_name(),org_name));
	CHAT_D->sys_channel(0,sprintf(HIY"%s"NOR"�����"HIY"%s"NOR"����ѳɹ�ռ����˫�ǣ�",who->get_name(),org_name));
	CHAT_D->sys_channel(0,sprintf(HIY"%s"NOR"�����"HIY"%s"NOR"����ѳɹ�ռ����˫�ǣ�",who->get_name(),org_name));
}

//����ν
void check_org_title(object who)
{
	if ( who->get_org_name() == get_save_2("occupy_org") )	
	{
		if ( who->get_org_position() == ORG_MASTER )
		{
			if ( !who->have_title("Z888") )
				who->add_title("Z888");
			if ( who->have_title("Z889") )
				who->delete_title("Z889");
		}
		else
		{
			if ( who->have_title("Z888") )
				who->delete_title("Z888");
			if ( !who->have_title("Z889") )
				who->add_title("Z889");
		}	
	}
	else
	{
		if ( who->have_title("Z888") )
			who->delete_title("Z888");
		if ( who->have_title("Z889") )
			who->delete_title("Z889");
	}
}
//������˫��ν
void org_title(string cName,int flag)
{
	int i,size;
	object orgnpc,who;
	string cTmp,*nName;

	orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", cName ) );
	if (!objectp(orgnpc))
		return ;
	size = orgnpc->sizeof_member_dbase();
	nName = orgnpc->get_all_member();
	for(i=0;i<size;i++)
	{
		who = find_char(nName[i]);
		if ( !who )
			continue;
		check_org_title(who);
		if ( flag )
		{
			if ( who->get_org_position() == ORG_MASTER )
				who->show_title("Z888");
			else
				who->show_title("Z889");
		}
	}	
}

void check_time()
{
	int iStart,iStart1,iFinish,date,i,size;
	mixed *mxTime;
	string *nTmp,org_name,master_name,cTmp;
	object orgnpc;
	
	remove_call_out("check_time");
	if ( iFlag == 1 )
	{
		call_out("check_time",3600*24);	
		return ;
	}
	mxTime = localtime(GET_TIME);
	date = mxTime[TIME_YEAR]*10000+ (mxTime[TIME_MON]+1)*100 + mxTime[TIME_MDAY];
	iStart = mktime(mxTime[TIME_YEAR],mxTime[TIME_MON]+1,mxTime[TIME_MDAY],START_ATT_HOUR,START_ATT_MIN,0);
	iFinish = mktime(mxTime[TIME_YEAR],mxTime[TIME_MON]+1,mxTime[TIME_MDAY],FINISH_ATT_HOUR,FINISH_ATT_MIN,0);
	if ( GET_TIME < iStart )	//����ǰ
	{
		call_out("check_time",iStart-GET_TIME);	
		if ( iWarStatus )
		{
			iWarStatus = 0;
			set_save_2("old_occupy_org",get_save_2("occupy_org"));
			save();	
		}
		return ;
	}
	if ( GET_TIME < iFinish )	//�����ڼ�
	{
		call_out("check_time",iFinish-GET_TIME);
		if ( !iWarStatus )
			iWarStatus = 1;
	}
	else	//���Ǻ�
	{
		mxTime = localtime(iStart+3600*24);	//�´ι���ʱ��
		iStart1 = mktime(mxTime[TIME_YEAR],mxTime[TIME_MON]+1,mxTime[TIME_MDAY],START_ATT_HOUR,START_ATT_MIN,0);
		call_out("check_time",iStart1-GET_TIME);
		if ( iWarStatus && iWarStatus < 5 )
			iWarStatus = 5;
	}
	if ( iWarStatus == 1 )
	{
		iWarStatus = 2;
		nTmp = get_save_2(sprintf("attack_list.%d.orgs",date));
		if ( check_war_time() == 1 )
		{
			size = sizeof(nTmp);
			for(i=0;i<size;i++)
			{
				"sys/sys/manager"->org_mail(0,nTmp[i],HIY"    ���Ｔ��������˫�ǣ����λ������������");
			}
			CHAT_D->sys_channel(0,"��˫������ս��ʼ�ˣ�");
		}
	}
	else if ( iWarStatus == 5 )	//����ɵ�����
	{
		iWarStatus = 0;
		set_save_2("old_occupy_org",get_save_2("occupy_org"));
		nTmp = get_save_2(sprintf("attack_list.%d.orgs",date));
		size = sizeof(nTmp);
		for(i=0;i<size;i++)
		{
			delete_save_2("join_org."+nTmp[i]);
		}
		delete_save_2(sprintf("attack_list.%d",date));
		if ( org_name=get_occupy_org() )
		{
			orgnpc = CITY_ZHOU->get_2( sprintf( "org.%s", org_name ) );
			if (objectp(orgnpc))
			{	
				master_name = orgnpc->get_master_name();
				cTmp = sprintf(HIR"��˫������ս��ʽ������"HIG"%s"HIR"����"HIG"%s"HIR"Ӣ�����쵼�³ɹ�ռ������˫�ǣ���Ҷ����ʾף�أ�����",org_name,master_name);
				for(i=0;i<4;i++)
				{
					CHAT_D->sys_channel(0,cTmp);
					send_user( CHAT_D->get_chat(), "%c%s", 0xA3, cTmp );
				}
			}
		}
	}
	save();
}
//�Ƿ���Խ�����˫��
int can_enter_palace(object who,object map)
{
	string org_name;

	org_name = get_save_2("occupy_org");
	if ( sizeof(org_name) &&  org_name == who->get_org_name() )	//ռ��İ���
		return 1;
	//����ʱ���ڲ��ܽ�ȥ
	if ( check_war_time() != 1 )
		return 0;
	return 1;
}
//�ж��Ƿ񹥳�ʱ��
int check_war_time()
{
	mixed *mxTime;	
	
	if ( iFlag == 1 )
		return 0;	
	mxTime = localtime(GET_TIME);
	if ( mxTime[TIME_HOUR] < START_ATT_HOUR 
		|| (mxTime[TIME_HOUR] == START_ATT_HOUR && mxTime[TIME_MIN] < START_ATT_MIN)
		|| (mxTime[TIME_HOUR] > FINISH_ATT_HOUR ) 	
		|| (mxTime[TIME_HOUR] == FINISH_ATT_HOUR && mxTime[TIME_MIN] >= FINISH_ATT_MIN) )
		return 0;
	return 1;
}
//��ѯռ��İ���
string get_occupy_org()	
{
	string org_name;
	
	org_name = get_save_2("occupy_org");
	return org_name?org_name:"";
}

//���û״̬	0 �ر� 1 ����
int set_flag(int i)
{
	iFlag = i;
	save();
	check_time();
	return iFlag;	
}
//��ȡ״̬
void get_status(object who)
{
	if ( iFlag == 0 )
		tell_user(who,"��˫����ս��ǰ��״̬�ǣ��ر�");	
	if ( iFlag == 1 )
	{
		tell_user(who,"��˫����ս��ǰ��״̬�ǣ�����");	
		tell_user(who,sprintf("���ʱ���ǣ�%02d��%02d�֣�%02d��%02d��",START_ATT_HOUR,START_ATT_MIN,FINISH_ATT_HOUR,FINISH_ATT_MIN));	
	}
	
}
//������Ϸʱ��
void set_wushuang_time(object who ,string tmp)
{
	int year,mon,day,hour,min,sec;		
	
	if ( sscanf(tmp,"%d-%d-%d %d:%d:%d",year,mon,day,hour,min,sec) != 6 )
	{
		send_user(who,"%c%s",'!',"�����ʱ���ʽ");
		return ;
	}
	tell_user(who,"��Ϸ�Ļʱ������Ϊ��%s",short_time(set_party_time(year,mon,day,hour,min,sec)));
	check_time();
	if ( iFlag == 0 )
		tell_user(who,"��˫����ս��ǰ��״̬�ǣ��ر�");
	else
		tell_user(who,"��˫����ս��ǰ��״̬�ǣ�����");
}