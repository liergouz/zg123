
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 5; }

// ��������Ʒ���
int get_fin_type() { return 2051; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(6174);
        set_picid_2(6174);

        set_level(90);
        set_value(6500);
        set_max_lasting(16899);
        set("ap", 0);
        set("dp", 155);
        set("cp", 0);
        set("pp", 236);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
