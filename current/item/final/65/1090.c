
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// ��������������
int get_family() { return 1; }

// ��������Ʒ���
int get_fin_type() { return 2055; }

// ���������촦��
void create()
{
        set_name("�����");
        set_picid_1(6562);
        set_picid_2(6562);

        set_level(90);
        set_value(6500);
        set_max_lasting(16899);
        set("ap", 0);
        set("dp", 175);
        set("cp", 0);
        set("pp", 56);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�����";
}
