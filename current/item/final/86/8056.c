
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit NECK;

// ��������������
int get_family() { return 8; }

// ��������Ʒ���
int get_fin_type() { return 1455; }

// ���������촦��
void create()
{
        set_name("��������");
        set_picid_1(8609);
        set_picid_2(8609);

        set_level(56);
        set_value(999);
        set_max_lasting(8599);
        set("ap", 77);
        set("dp", 0);
        set("cp", 121);
        set("pp", 78);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��������";
}
