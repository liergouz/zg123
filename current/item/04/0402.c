#include <effect.h>
inherit ITEM;
inherit COMBINED;

int is_usable() { return 1; }
// ��������������
int get_max_combined() { return 30; }

int is_worldcup() { return 1; }

// ���������촦��
void create()
{
        set_name("����ɫ�����");
        set_picid_1(3566);
        set_picid_2(3566);
        set_unit("ֻ");
        set_value(10);
        set_amount(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return "��ע���籭�����������μӱ�������ͶƱ��һ����ʱ���ߡ���ֵ��10��\n��ʱ���������ֵ10%��Ч������60���ӡ�"; 
}

int get_use_effect(object who) { return __FILE__->get_use_effect_callout(who,this_object()); }

int get_use_effect_callout(object who,object item)
{
	if ( time() > mktime(2006,7,9,0,0,0) )	
	{
		item->remove_from_user();
		destruct(item);
		return 0;
	}
//	if ( gone_time(who->get("qiupai2")) < 1 ) 
//		return 0;
//	who->set("qiupai2",time());
//	set_effect_2(who, EFFECT_QIUPAI_MP,  1, 3600);
//	USER_ENERGY_D->count_max_mp(who);
//	return 1;
}

void effect_break(object who)
{
//	set_effect(who, EFFECT_QIUPAI_MP, 0);
//	USER_ENERGY_D->count_max_mp(who);
}