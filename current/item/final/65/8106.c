
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// ��������������
int get_family() { return 8; }

// ��������Ʒ���
int get_fin_type() { return 2372; }

// ���������촦��
void create()
{
        set_name("�����");
        set_picid_1(6578);
        set_picid_2(6578);

        set_level(106);
        set_value(1000);
        set_max_lasting(23899);
        set("ap", 0);
        set("dp", 74);
        set("cp", 0);
        set("pp", 128);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�����";
}
