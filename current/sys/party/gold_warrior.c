/*******************************
	**�ƽ����ӳ�**
*******************************/

#include <time.h>
#include <ansi.h>
//#include <cmd.h>
//
//#include <npc.h>
//#include <city.h>
//#include <action.h>
//#include <effect.h>
//#include <skill.h>
//#include <public.h>

int warrior=0;
int nnn=0;
// ���������ɶ�������
void SAVE_BINARY() { }

void create()
{
	call_out("check_time",1);
}

void check_time()
{
	int iTime,rate,level,z,p,x,y;
	int i,*nScene,size;
	mixed *mixTime;
	object robber;
	
	remove_call_out("check_time");
	iTime = time();
	
	mixTime = localtime(iTime);

	if ( mixTime[TIME_WDAY] == 5 || mixTime[TIME_WDAY] == 6 )
	{
		call_out("check_time",3600*24);
		return ;
	}
	if ( mixTime[TIME_WDAY] == 0 )
	{
		call_out("check_time",3600*24-mixTime[TIME_HOUR]*3600-mixTime[TIME_MIN]*60);
		return ;
	}
	if ( mixTime[TIME_HOUR] < 7  )
	{
		call_out("check_time",60*(60-mixTime[TIME_MIN]));
		return ;
	}
	if ( mixTime[TIME_HOUR]%2 == 1 && mixTime[TIME_MIN] < 55 )
	{
		i = 60*(55-mixTime[TIME_MIN]);
		call_out("check_time",i+3600);
		return ;
	}
	if ( mixTime[TIME_HOUR]%2 == 0 && mixTime[TIME_MIN] < 55 )
	{
		i = 60*(55-mixTime[TIME_MIN]);
		call_out("check_time",i);
		return ;
	}
	CHAT_D->sys_channel(0,HIR"���ӳ�ÿ�������������㿪ʼ�����Լ��ǻƽ�ʥ��ʿ����ȥ��������ʲô��Ҫ��æ�ģ�");
	log_file( "gold_warrior.dat", sprintf( "%d ��%d �ƽ����ӳ���������\n",mixTime[TIME_HOUR],mixTime[TIME_MIN]) );
//	nnn ++;
	call_out("check_time2",60*(60-mixTime[TIME_MIN]));
	call_out("check_time",7200-60*(mixTime[TIME_MIN]-55));
/*	else
	{
		if (mixTime[TIME_MIN]<=55)
		{
			i = 60*(55-mixTime[TIME_MIN]);
			if ( mixTime[TIME_HOUR]%2 == 1 )
			{
				call_out("check_time",i+3600);
			}
			else
			{
				CHAT_D->sys_channel(0,HIR"���ӳ�ÿ�������������㿪ʼ�����Լ��ǻƽ�ʥ��ʿ����ȥ��������ʲô��Ҫ��æ�ģ�");
				nnn ++;
				call_out("check_time2",300);
				call_out("check_time",i);
			}
		}
		else
		{
			i = 60*(mixTime[TIME_MIN]-55);
			if ( mixTime[TIME_HOUR]%2 == 1 )
			{
				call_out("check_time",i);
				call_out("check_time2",(60-mixTime[TIME_HOUR])*60);
			}
			else
			{
//				CHAT_D->sys_channel(0,HIR"���ӳ�ÿ�������������㿪ʼ�����Լ��ǻƽ�ʥ��ʿ����ȥ��������ʲô��Ҫ��æ�ģ�");
				call_out("check_time",i+3600);
			}			
		}
	}*/
}

void check_time2()
{
	CHAT_D->sys_channel(0,HIR"���ӳ��Ѿ���ʼѰ�һƽ�ʥ���ˣ��Ͽ�ȥ�������ɣ�");
	warrior=1;
	call_out("check_time3",120);
}

void check_time3()
{
	warrior=0;
}

int get_warrior()
{
	return warrior;	
}

int get_nnn()
{
	return nnn;	
}


