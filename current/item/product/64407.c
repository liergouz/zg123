
// �Զ����ɣ�/make/item/make90
#include <item.h>
inherit ITEM;
inherit USABLE;

// ������ͼֽ���
int get_product_type() { return 407; }

// ������ͼֽҪ����
int get_product_skill() { return 640; }

// ������ͼֽҪ�����
int get_product_sort() { return 0; }

// ������ͼֽҪ��ȼ�
int get_product_level() { return 70; }

// ������ͼֽҪ��������
int get_product_exp() { return 73; }

// ��������ʹ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_PRODUCT; }

int get_item_color() { return 1; }

// ���������촦��
void create()
{
        set_name("ҫ�ճ���ͼֽ");
        set_picid_1(9807);
        set_picid_2(9807);
        set_value(2000);
}

// ��������ȡ����
string get_desc()
{
        return "ѧϰ����ҫ�ճ���";
}

string get_product()
{
	return "/item/final/60/7085";
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return "/sys/item/product" ->get_use_effect(me, this_object()); }
