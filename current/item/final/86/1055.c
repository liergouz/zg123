
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit NECK;

// ��������������
int get_family() { return 1; }

// ��������Ʒ���
int get_fin_type() { return 1349; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8612);
        set_picid_2(8612);

        set_level(55);
        set_value(20000);
        set_max_lasting(8599);
        set("ap", 71);
        set("dp", 0);
        set("cp", 0);
        set("pp", 75);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
