
// �Զ����ɣ�/make/item/make89a

#include <item.h>

inherit ITEM;
inherit "/inh/item/diamond";

// ��������ʯʶ��
int is_diamond_2() { return 1; }

// ��������Ҫȷ������
int confirm_sell_item() { return 1; }

// ��������ʯʶ��
int get_item_type() { return ITEM_TYPE_DIAMOND_2; }

// ��������ʯ����
string get_diamond_type() { return "mp%"; }

// ���������촦��
void create()
{
        set_name("��ȱ��쾧ʯ");
        set_picid_1(8904);
        set_picid_2(8904);
        set_unit("��");
        set_value(20000);
        set_bonus_value(5500);
}

// ��������ȡ����
string get_desc() 
{ 
        return "�۱�ʯ�ϳɲ��ϣ����ӷ����ٷֱ�"; 
}

// ���������ɱ�ʯ�ļ�
string get_diamond_file()
{
        return __DIR__ "8954";
}
