from flask import Flask
from web.routes.game_route import game_bp


def create_app():
    app = Flask(__name__)
    app.register_blueprint(game_bp)
    return app
