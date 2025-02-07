//makesellcard.c�Զ�����
#include <ansi.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;   

int card_id;
int card_time;

int get_item_value() {return 2 ;}
int get_item_value_2() {return 2 ;}
int get_item_number() {return 10001060 ;}
int get_item_color() {return 1 ;}

//���ñ���ID
int set_card_id(int i) { return card_id = i;}
//��ȡ����ID
int get_card_id() { return card_id;}
//���ñ���ʱ��
int set_card_time(int i) { return card_time = i;}
//��ȡ����ʱ��
int get_card_time() { return card_time;}

// ���������촦��
void create()
{
        set_name("�����");
        set_picid_1(3811);
        set_picid_2(3811);
        set_value(20);
        set_card_id(4142);
        set_card_time(3600);
        set_amount(1);
}
// ��������ȡ����
string get_desc() 
{ 
        return "����1Сʱ�ڱ���Ϊ�߼������������2%�����������"; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}
//ʹ�ú��Ӱ��
int get_use_effect_callout( object who,object item) 
{
	send_user( who, "%c%c%w%s", ':', 3, 0,sprintf("��ȷ��Ҫʹ��%s��\n"ESC"ȷ��\nuse ! %x#\n"ESC"ȡ��",item->get_name(),getoid(item))); 
	return 0;
}

// ������ʹ��Ч��
int confirm_use( object me ) { return __FILE__ ->confirm_use_callout( me, this_object() ); }

// ������ʹ��Ч��(���߸���)
int confirm_use_callout( object who, object item )
{
	int dp;
	if ( "sys/sys/magic_card"->change_shape(who,item->get_card_id(),item->get_card_time()) != 1 )
		return 0;
	dp = who->get_dp()*2/100;
	who->set_2("magic_card.dp",dp);
	USER_ENERGY_D->count_dp(who);
	return 1;
}
void remove_effect(object who)
{
	int dp;
	
	dp = who->get_2("magic_card.dp");
	if ( !dp )
		return ;
	who->delete_2("magic_card.dp");	
	USER_ENERGY_D->count_dp(who);
}


