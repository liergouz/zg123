
#include <item.h>
#include <ansi.h>

inherit ITEM;

private int Money;
private int OrginMoney;

// ��ʹ��
int is_usable() {return 1;}

// ����������ǮƱ
// int is_cheque() { return 1; }

// ����������ǮƱ
int get_item_type() { return ITEM_TYPE_CHEQUE2; }

// ��������ȡǮƱ���
int get_money() { return Money; }

// ����������ǮƱ���
int set_money( int gold ) { return Money = gold; }

// ����������ǮƱ���
int add_money( int gold ) { return Money += gold; }

// ��������ȡǮƱ����
int get_orgin_money() { return OrginMoney; }

// ����������ǮƱ����
int set_orgin_money( int gold ) { return OrginMoney = gold; }

// ���������촦��
void create()
{
        set_name("��Ʊ");
        set_picid_1(0008);
        set_picid_2(0008);
        set_unit("��");

        set_no_drop(1);
        set_no_get(1);
        set_no_give(1);
        set_no_sell(1);
}

// ��������ȡ����
string get_desc() 
{ 
        return sprintf( "����ר��ǮƱ����������ְҵ" ); 
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me, this_object()); }

// ������ʹ��Ч��(���߸���)
int get_use_effect_callout( object me, object obj)
{
        string result;
        result = sprintf("ͨ����Ʊ������ר�ã�\nԭ��ֵ��  %d ��\n",  obj->get_orgin_money());
        if (obj->get_money()<=obj->get_orgin_money()/2)
                result += sprintf("����ֵ��"HIR"  %d "NOR"��\n", obj->get_money());
        else                
        if (obj->get_money() - me->get_save_2("mastertask.targetxy") >=obj->get_orgin_money())
                result += sprintf("����ֵ��"HIG"  %d "NOR"��\n", obj->get_money());                
        else
                result += sprintf("����ֵ��  %d ��\n", obj->get_money());               
        if (me->get_save_2("mastertask.type")==11)
                result += sprintf("����Ҫ��׬ȡ %d ��", me->get_save_2("mastertask.targetxy"));
        send_user( me, "%c%s", ';', result );                                

        return 0;
}