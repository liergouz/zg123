
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 6; }

// ��������Ʒ���
int get_fin_type() { return 2031; }

// ���������촦��
void create()
{
        set_name("ӫ������");
        set_picid_1(6034);
        set_picid_2(6034);

        set_level(80);
        set_value(6000);
        set_max_lasting(15899);
        set("ap", 0);
        set("dp", 129);
        set("cp", 0);
        set("pp", 209);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "ӫ������";
}
