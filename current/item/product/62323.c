
// �Զ����ɣ�/make/item/make90
#include <item.h>
inherit ITEM;
inherit USABLE;

// ������ͼֽ���
int get_product_type() { return 323; }

// ������ͼֽҪ����
int get_product_skill() { return 620; }

// ������ͼֽҪ�����
int get_product_sort() { return 1; }

// ������ͼֽҪ��ȼ�
int get_product_level() { return 65; }

// ��������ʹ����Ʒ
int get_item_type_2() { return ITEM_TYPE_2_PRODUCT; }

int get_item_color() { return 1; }

// ���������촦��
void create()
{
        set_name("�Ʋ�ȭ��ͼֽ");
        set_picid_1(9807);
        set_picid_2(9807);
        set_value(200);
}

// ��������ȡ����
string get_desc()
{
        return "ѧϰ�����Ʋ�ȭ�ס�";
}

string get_product()
{
	return "/item/final/70/1065";
}

// ������ʹ��Ч��
int get_use_effect( object me ) { return "/sys/item/product" ->get_use_effect(me, this_object()); }
