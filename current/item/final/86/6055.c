
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit NECK;

// ��������������
int get_family() { return 6; }

// ��������Ʒ���
int get_fin_type() { return 1355; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8612);
        set_picid_2(8612);

        set_level(55);
        set_value(20000);
        set_max_lasting(8599);
        set("ap", 0);
        set("dp", 0);
        set("cp", 115);
        set("pp", 80);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
