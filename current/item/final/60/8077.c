
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 8; }

// ��������Ʒ���
int get_fin_type() { return 2351; }

// ���������촦��
void create()
{
        set_name("������");
        set_picid_1(6074);
        set_picid_2(6074);

        set_level(77);
        set_value(1000);
        set_max_lasting(18899);
        set("ap", 0);
        set("dp", 115);
        set("cp", 0);
        set("pp", 202);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "������";
}
