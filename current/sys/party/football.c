/*****��ɫ����****/

#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <public.h>
#include <time.h>
#include <action.h>

// ���������ɶ�������
void SAVE_BINARY() { }
// ���������촦��
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

	if ( mixTime[TIME_WDAY] < 5 && mixTime[TIME_WDAY] != 0 )
	{
		call_out("check_time",3600*12);
		return ;
	}
	if ( mixTime[TIME_HOUR] < 17  )
	{
		call_out("check_time",60*(60-mixTime[TIME_MIN]));
		return ;
	}
	if ( mixTime[TIME_MIN] < 55  )
	{
		call_out("check_time",60*(55-mixTime[TIME_MIN]));
		return ;
	}
	CHAT_D->sys_channel(0,sprintf(HIY"��˵"HIR"%d���Ӻ�"HIY"�ɶ�Ĺ������ֿ�ʼ�����ƻ��������������ˣ���Ϊս����ʿ��Ӧ���ڵ�һʱ���ڽ����ǵ����������������������򶼿���"HIR"�һ���ʹ"HIY"��ȡ���꣡",60-mixTime[TIME_MIN]));
	call_out("check_time2",60*(60-mixTime[TIME_MIN]));
	call_out("check_time",3600*54);	
}

void check_time2()
{
	CHAT_D->sys_channel(0,HIY"�������������ʼ�ˣ�����ʿ�Ǹ��͸�λ�������ǵ�������������ʹ��Щ����ɱ�ֲ������ţ�"HIR"������Ҷһ���ʹ��ȡ�����ı��꣡");
}