
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
string get_diamond_type() { return "%s"; }

// ���������촦��
void create()
{
        set_name("%s");
        set_picid_1(%d);
        set_picid_2(%d);
        set_unit("%s");
        set_value(%d);
        set_bonus_value(%d);
}

// ��������ȡ����
string get_desc() 
{ 
        return "�۱�ʯ�ϳɲ��ϣ�%s"; 
}

// ���������ɱ�ʯ�ļ�
string get_diamond_file()
{
        return __DIR__ "%d";
}
